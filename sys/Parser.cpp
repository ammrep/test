#include "Parser.h";
#include "../apps/echo/Echo.h";
#include "../exceptions/AppErrorException.h";
#include <iostream>
using std::cout;
using std::endl;

Parser::Parser()
{

}

void Parser::parse(string input)
{
    cout << "Парсим строку: " << input << endl;
	if (input == "error")
		throw AppErrorException();
	if (input == "echo")
	{
		Echo echo;
		echo.run();
	}
	else
	if (input != "exit")
		cout << "Команда не найдена!" << endl;
}