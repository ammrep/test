/**
* Класс Cd - основной класс приложения Cd - реализация интерфейса
* IApp
*/

#ifndef CD_H
#define CD_H

#include <vector>
using std::vector;

#include "../../sys/IApp.h"    //подключаем интерфейс
#include "../../sys/TData.cpp"

class Cd : public IApp 
{
public:
	Cd();
	/**
	* Функция run() запускает приложение Cd
	*/
	void run(vector<TData>);
	//void getHelp();
private:
	//void setKeys(vector<TData>);
	//bool checkParameters(vector<TData>);
	//bool newlines;
	//bool reverseOutput;
	//bool help;
};

#endif