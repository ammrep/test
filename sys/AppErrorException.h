/**
* Класс AppErrorExeption - класс исключений. Пока он единственный, тестовый. Потом
* будут классы для каждого типа ошибок
*/
#ifndef APPERROREXCEPTION_H
#define APPERROREXCEPTION_H

#include <stdexcept>
using std::runtime_error;
using std::invalid_argument;

class AppErrorException : public runtime_error
{
public:
	AppErrorException()
		: runtime_error("Ошибка приложения ") {}
};

class InvalidKey : public invalid_argument
{
public:
	InvalidKey(string key) 
		: invalid_argument(key) {}
};

#endif