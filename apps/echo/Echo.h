/**
* Класс Echo - основной класс приложения Echo - реализация интерфейса
* IApp
*/
#include "../../sys/IApp.h"    //подключаем интерфейс
#include "../../sys/TData.cpp"
#include<vector>
using std::vector;

class Echo : public IApp 
{
public:
	Echo();

	/**
	* Функция run() запускает приложение Echo
	*/
	void run(vector<TData>&);

};
