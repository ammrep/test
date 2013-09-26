/**
* Класс Echo - основной класс приложения Echo - реализация интерфейса
* IApp
*/
#include "../../sys/IApp.h"    //подключаем интерфейс

class Echo : public IApp 
{
public:
	Echo();

	/**
	* Функция run() запускает приложение Echo
	*/
	void run();

};
