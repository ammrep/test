/**
* Класс IApp - интерфейс для любого приложения шелла
**/

class IApp {
public:
	/**
	* Функция run() запускает приложение
	*/
	void run();
	void getHelp();
private:
	void checkKeys();
	void checkParameters();
};