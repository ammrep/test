#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include "Echo.h"
#include "../../sys/TData.cpp"
#include "../../sys/AppErrorException.h"

Echo::Echo() {}

void Echo::run(vector<TData> command)
{
	// Если у комманды нет параметров
	if (!checkParameters(command)) {
		getHelp();
		return;
	}

	setKeys(command); 		// Обработка ключей, входящих в комманду

	// Если в команде задан ключ -h
	if (help) {
		getHelp();
		return;
	}

	// Обработка ключа, задающего разделитель между параметрами
	char sep = (newline ? '\n' : ' ');

	// Вывод
	bool isThereOutput = false;
	for (size_t i = 1; i < command.size(); i++) 
		if (command.at(i).type == PARAMETER) {
			isThereOutput = true;
			cout << command.at(i).str << sep;
		}

	if (isThereOutput && !newline)
		cout << endl;
}

/**
Присваивает true булевым переменным, для которых в комманде
есть соответствующие ключи
*/
void Echo::setKeys(vector<TData> command)
{
	help = newline = reverse = false;
	for (size_t i = 1; i < command.size(); i++)
		if (command.at(i).type == KEY || command.at(i).type == LONG_KEY) {
			string temp = command.at(i).str;
			if (temp == "h" || temp == "help")
				help = true;
			else if (temp == "n" || temp == "new-line")
				newline = true;
			else if (temp == "r" || temp == "reverse")
				reverse = true;
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