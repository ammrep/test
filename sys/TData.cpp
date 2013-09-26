#ifndef TDATA_CPP
#define TDATA_CPP

#include <string>
using std::string;

struct TData
{
	string str;    // часть команды
	char type;    /* тип - 'c' - команда
                           'k' - ключ, 
                           'd' - доп. ключ, 
                           'n' - параметр, 
                           's' - строка , 
                           'v' - переменная */
};

#endif