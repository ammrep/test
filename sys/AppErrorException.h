/**
* Класс AppErrorExeption - класс исключений. Пока он единственный, тестовый. Потом
* будут классы для каждого типа ошибок
*/
#include <stdexcept>
using std::runtime_error;

class AppErrorException : public runtime_error
{
public:
	AppErrorException()
		: runtime_error("Ошибка приложения ") {}
};