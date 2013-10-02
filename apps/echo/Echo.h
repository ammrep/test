/**
* Класс Echo - основной класс приложения Echo - реализация интерфейса
* IApp
*/

#ifndef ECHO_H
#define ECHO_H

#include <vector>
using std::vector;

#include "../../sys/IApp.h"    //подключаем интерфейс
#include "../../sys/TData.cpp"

class Echo : public IApp 
{
public:
	Echo();
	~Echo();
	/**
	* Функция run() запускает приложение Echo
	*/
	void run(vector<TData>);
private:
	void setKeys(vector<TData>);
	bool checkParameters(vector<TData>);
	bool newline;
	bool reverse;
	bool help;
};

#endif