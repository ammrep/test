#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <stdexcept>
using std::invalid_argument;

#include "Echo.h"
#include "../../sys/TData.cpp"
#include "../../sys/AppErrorException.h"

Echo::Echo(vector<TData> command)
{ 
	this->run(command);
}

void Echo::run(vector<TData> command)
{
	if (!checkParameters(command)) {
		getHelp();
		return;
	}
	setKeys(command); 		// Обработка ключей, входящих в комманду
	if (help) {
		getHelp();
		return;
	}

	char sep = (newline ? '\n' : ' ');

	bool isThereOutput = false;
	for (size_t i = 0; i < command.size(); i++) 
		if (command.at(i).type == QPARAMETER) {
			isThereOutput = true;
			cout << command.at(i).str << sep;
		}
	if (isThereOutput && !newline)
		cout << endl;
}

void Echo::setKeys(vector<TData> command)
{
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

bool Echo::checkParameters(vector<TData> command)
{
	bool isThereQParam = false;
	for (int i = 1; i < command.size(); i++) { 
		if (command.at(i).type == PARAMETER) {
			cout << "Неверный параметр: " << command.at(i).str << endl;
			return false;
		}
		else if (command.at(i).type == QPARAMETER)
			isThereQParam = true;
	}
}