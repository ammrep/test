#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <fstream>
using std::ifstream;

#include <algorithm>
using std::reverse;

#include "Echo.h"
#include "../../sys/TData.cpp"
#include "../../sys/AppErrorException.h"

Echo::Echo() {}

void Echo::run(vector<TData> command)
{

	setKeys(command); 		// Обработка ключей, входящих в комманду

	// Если у комманды нет параметров
	if (!checkParameters(command)) {
		cout << "Программе не передано параметров" << endl;
		help = true;
	}
	
	// Если в команде задан ключ -h
	if (help) {
		getHelp();
		return;
	}

	// Обработка ключа, задающего разделитель между параметрами
	char sep = (newlines ? '\n' : ' ');

	if (reverseOutput)
		reverse(command.begin()+1, command.end());
	
	// Вывод
	bool isThereOutput = false;
	for (size_t i = 1; i < command.size(); i++) 
		if (command.at(i).type == PARAMETER) {
			isThereOutput = true;
			cout << command.at(i).str << sep;
		}

	if (isThereOutput && !newlines)
		cout << endl;
}

/**
Присваивает true булевым переменным, для которых в комманде
есть соответствующие ключи
*/
void Echo::setKeys(vector<TData> command)
{
	help = newlines = reverseOutput = false;
	for (size_t i = 1; i < command.size(); i++)
		if (command.at(i).type == KEY || command.at(i).type == LONG_KEY) {
			string temp = command.at(i).str;
			if (temp == "h" || temp == "help")
				help = true;
			else if (temp == "n" || temp == "new-line")
				newlines = true;
			else if (temp == "r" || temp == "reverse")
				reverseOutput = true;
			else
				throw InvalidKey(command.at(i).str);
		}
}

/**
Проверяет, корректно ли заданы параметры в команде
*/
bool Echo::checkParameters(vector<TData> command)
{
	for (size_t i = 1; i < command.size(); i++) 
		if (command.at(i).type == PARAMETER)
			return true;
	return false;
}

void Echo::getHelp()
{
	const char* filename = "apps/echo/help";
	char c;
	ifstream fin(filename);

	cout << "\n\n";
	while (fin.get(c)) 
		cout << c;
	if (c != '\n')
		cout << "\n\nКонец справки\n\n";
}