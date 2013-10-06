/**
* Класс ControllerErrorException - класс исключения для ошибок контроллера
*/

#ifndef CONTROLLERERROREXCEPTION_H
#define CONTROLLERERROREXCEPTION_H

#include <stdexcept>
using std::runtime_error;

#include <string>
using std::string;

class ControllerErrorException : public runtime_error
{
public:
	ControllerErrorException(string error)
		: runtime_error(error) {}
};

#endif 