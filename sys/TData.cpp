#ifndef TDATA_CPP
#define TDATA_CPP

#include <string>
using std::string;

struct TData
{
	string str;    // часть команды
	char type;    // тип - 'n' - имя файла, 'k' - ключ, 'd' - доп. ключ, 's' - строка , 'v' - переменная
};

#endif