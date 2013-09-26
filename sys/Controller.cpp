#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "Controller.h"
#include "Parser.h"

#include "TData.cpp"

Controller::Controller()
{
	cout << "Создан экземпляр контроллера" << endl;
}

Controller::~Controller()
{
	cout << "Удалён экземпляр контроллера" << endl;
}

void Controller::run()
{
	vector<TData> command;
	string input;
	cout << "Запущено приложение Shell" << endl;
	Parser pars;
	input = "";    // начальное значение
	while (input != "exit")
	{
		//cin >> input;
		cout << "~ $: ";
		getline(cin,input);
		command = pars.parse(input);    // парсим строчку
	}
}

