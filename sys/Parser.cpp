﻿#include <iostream>
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

	return command;
}

vector<TData> Parser::getTokens(string input)
{
	vector<TData> Data;
    TData d;
    istringstream ist(input);
    string tmp;
    
    if (input.empty())
    	return Data;

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
			d.type = KEY;
			// Для обработки серии ключей вида -lar
			for (size_t i = 1; i < tmp.length() - 1; i++) {
				d.str = tmp[i];
				Data.push_back(d);
			}
			d.str = *(tmp.end()-1);	// чтобы не пропустить последний ключ в серии
		}
		else if (tmp[0] == '\"' || tmp[0] == '\'')
		{
			while (*(tmp.end()-1) != tmp[0]) {
				char c;
				ist.get(c);
				tmp.push_back(c);
			}
			d.str = tmp.substr(1,tmp.length() - 2);
			d.type = QPARAMETER;
		}
		else
		{
			d.str = tmp;
			d.type = PARAMETER;
		};
		Data.push_back(d);
	};
	return Data;
}