#ifndef TDATA_CPP
#define TDATA_CPP

#include <string>
using std::string;

enum Type {COMMAND, KEY, LONG_KEY, PARAMETER};

struct TData
{
	string str;    // часть команды
	Type type;
};

#endif