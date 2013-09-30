#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>
using std::binary_search;

#include "Controller.h"
#include "Parser.h"
#include "ControllerErrorException.h"
#include "../apps/echo/Echo.h"

#include "TData.cpp"

Controller::Controller()
{
	cout << "Создан экземпляр контроллера" << endl;
	this->app_names.push_back("echo");    // регестрируем имя приложения(команды)
	this->app_names.push_back("exit"); 
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
		if (binary_search(this->app_names.begin(),this->app_names.end(),command[0].str))
		{
			cout << "Приложение " << command[0].str << " найдено в списке регистрации. Запускаю!" << endl;
			if (command[0].str == "echo")
			{
				Echo eh;
				eh.run();
			}
		}
		else
		{
			throw ControllerErrorException("Такое приложение не существует");
		}
	}
}
