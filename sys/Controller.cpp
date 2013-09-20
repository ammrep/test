#include "Controller.h"
#include "Parser.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::cin;
using std::string;
//typedef std::string< char > string;
//string input;

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
	string input;
	cout << "Запущено приложение Shell" << endl;
	cin >> input;
	Parser pars;
	pars.parse(input);    // парсим строчку
}

