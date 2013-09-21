#include "Controller.h"
#include "Parser.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::cin;
using std::string;

Controller::Controller()
{
	cout << "—оздан экземпл€р контроллера" << endl;
}

Controller::~Controller()
{
	cout << "”далЄн экземпл€р контроллера" << endl;
}

void Controller::run()
{
	string input;
	cout << "«апущено приложение Shell" << endl;
	Parser pars;
	input = "";    // начальное значение
	while (input != "exit")
	{
		cin >> input;
		pars.parse(input);    // парсим строчку
	}
}

