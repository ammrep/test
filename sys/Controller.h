/**
* Класс Controller создаётся первым и запускает shell.
* Его предназначение - получение строки от пользователя и запуск 
* запрошенного приложения, контроль за приложениями, и обеспечение
* доступа к общим данным (переменным и текущей директории). Этот 
* класс вызывает все остальные классы, и нужно постараться, чтобы
* все связи происходили через него
*/
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
using std::vector;

#include <string>
using std::string;

class Controller 
{
public:
	Controller();
	~Controller();

	/**
	* Функция run() запускает shell
	*/
	void run();
private:
	vector<string> app_names;	// имена всех приложений
};

#endif