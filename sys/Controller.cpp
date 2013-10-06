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
using std::sort;

#include "Controller.h"
#include "Parser.h"
#include "ControllerErrorException.h"
#include "AppErrorException.h"
#include "../apps/apps.h"
#include "TData.cpp"

Controller::Controller()
{
	// cout << "Создан экземпляр контроллера" << endl;
	this->app_names.push_back("echo");    // регистрируем имя приложения(команды)
	this->app_names.push_back("exit"); 
	this->app_names.push_back("cd");  
	sort(this->app_names.begin(), this->app_names.end());
}

Controller::~Controller()
{
	// cout << "Удалён экземпляр контроллера" << endl;
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
		try {
			cout << "~ $: ";
			getline(cin,input);
			command = pars.parse(input);    // парсим строчку

			if (!command.empty() && binary_search(this->app_names.begin(), 
			                        this->app_names.end(), command.at(0).str))
			{
				if (command.at(0).str == "echo")
				{
					Echo echo;
					echo.run(command);
				}
				if (command.at(0).str == "cd")
				{
					Cd cd;
					cd.run(command);
				}
			}
			else if (!command.empty())
			{
				throw ControllerErrorException("Такое приложение не существует");
			}
		}
		catch (ControllerErrorException &ControllerErrorException)
		{
			cout << "Обнаружена ошибка: " << ControllerErrorException.what() << endl; 
		}
		catch (InvalidKey &ik)
		{
			cout << "Некорректный ключ: " << ik.what() << endl;
		}
	}
}
