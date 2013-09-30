#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <sstream>
using std::string;
using std::istringstream;

#include "Parser.h"
#include "../apps/echo/Echo.h"
#include "AppErrorException.h"
#include "TData.cpp"

Parser::Parser()
{

}

vector<TData> Parser::parse(string input)
{
	vector<TData> command = getTokens(input);

	if (command.at(0).str == "error")
		throw AppErrorException();
	if (command.at(0).str == "echo")
	{
		Echo echo;
		echo.run();
	}
	//else if (command.at(0).str != "exit")
	//	cout << "Команда не найдена!" << endl;
	return command;
}

vector<TData> Parser::getTokens(string input)
{
	vector<TData> Data;
    TData d;
    istringstream ist(input);
    string tmp;
    
    while ( ist >> tmp )
	{
		//cout << tmp << endl;
		if (Data.empty()) {
			d.str = tmp;
			d.type = COMMAND;
		}
		else if (tmp[0] == '-' && tmp[1] == '-')
		{
			d.str = tmp.substr(2,tmp.length());
			d.type = LONG_KEY;
		}
		else if (tmp[0] == '-')
		{
			d.str = tmp.substr(1,tmp.length());
			d.type = KEY;
		}
		else if (tmp[0] == '\"' || tmp[0] == '\'')
		{
			while (*(tmp.end()-1) != tmp[0]) {
				char c;
				ist.get(c);
				tmp.push_back(c);
			}
			d.str = tmp.substr(1,tmp.length() - 2);
			d.type = PARAMETER;
		};
		Data.push_back(d);
	};
	return Data;
}