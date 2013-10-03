/**
* Класс Echo - основной класс приложения Echo - реализация интерфейса
* IApp
*/

#ifndef ECHO_H
#define ECHO_H

#include <vector>
using std::vector;

#include <string>
using std::string;

#include "../../sys/IApp.h"    //подключаем интерфейс
#include "../../sys/TData.cpp"

class Echo : public IApp 
{
public:
	Echo();
	/**
	* Функция run() запускает приложение Echo
	*/
	void run(vector<TData>);
	void getHelp();
private:
	void setKeys(vector<TData>);
	bool checkParameters(vector<TData>);
	bool newlines;
	bool reverseOutput;
	bool help;
};

#endif