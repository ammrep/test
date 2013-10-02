#ifndef TDATA_CPP
#define TDATA_CPP

#include <string>
using std::string;

enum Type {COMMAND, 		// имя запускаемой программы
           KEY, 			// короткие ключи. Пример: -r, -a
           LONG_KEY, 		// расширенные ключи. Пример: --reverse, -all
           QPARAMETER,		// закавыченные параметры для строк и параметров с пробелами
           PARAMETER};		// обычный параметр, без пробелов и кавычек

struct TData
{
	string str;    // часть команды
	Type type;
};

#endif