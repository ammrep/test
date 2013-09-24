#include "Parser.h";
#include "../apps/echo/Echo.h";
#include "../exceptions/AppErrorException.h";
#include <iostream>
#include <vector>
#include <sstream>
using std::vector;
using std::cout;
using std::endl;
using std::string;

struct TData
{
	string str;    // часть команды
	char type;    // тип - 'n' - имя файла, 'k' - ключ, 'd' - доп. ключ, 's' - строка , 'v' - переменная
};

Parser::Parser()
{

}

void Parser::parse(string input)
{
	vector<TData> Data;

    TData d;

	/*d.str = "echo";
	d.type = 'n';
	Data.push_back(d);

	d.str = "-dd";
	d.type = 'k';
	Data.push_back(d);

	d.str = "--dd";
	d.type = 'd';
	Data.push_back(d);*/

	//cout << "Вывод элементов вектора: " << Data[0].str << " " << Data[0].type << " "  << Data[1].str << " " << Data[1].type << " "  << Data[2].str << " " << Data[2].type << endl;

    std::istringstream ist(input);
    string tmp;
    while ( ist >> tmp )
	{
		//cout << tmp << endl;
		if (tmp[0] == '-' && tmp[1] == '-')
		{
			d.str = tmp.substr(2,tmp.length());
			d.type = 'd';	// дополнительный ключ
			cout << "Тип строки: " << d.type << endl;	// оставил для отладки
			cout << "Строка: " << d.str << endl;
		}
		else
		if (tmp[0] == '-')
		{
			d.str = tmp.substr(1,tmp.length());
			d.type = 'k';	// ключ
			cout << "Тип строки: " << d.type << endl;
			cout << "Строка: " << d.str << endl;
		}
		else
		if (tmp[0] == '"' && tmp[tmp.length() - 1] == '"')
		{
			d.str = tmp.substr(1,tmp.length() - 2);
			d.type = 's';	// строка
			cout << "Тип строки: " << d.type << endl;
			cout << "Строка: " << d.str << endl;
		}
		else
		if (tmp[0] == '$')
		{
			d.str = tmp.substr(1,tmp.length());
			d.type = 'v';	// переменная
			cout << "Тип строки: " << d.type << endl;
			cout << "Строка: " << d.str << endl;
		}
		else
		{
			d.str = tmp;
			d.type = 's';	// строка
			cout << "Тип строки: " << d.type << endl;
			cout << "Строка: " << d.str << endl;
		}

	};

    //cout << "Парсим строку: " << input << endl;
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