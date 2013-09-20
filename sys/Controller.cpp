#include "Controller.h"

Controller::Controller()
{
	cout << "Создан экземпляр контроллера" << endl;
}

Controller::~Controller()
{
	cout << "Удалён экземпляр контроллера" << endl;
}

void Controller::run()
{
	cout << "Запущено приложение Shell" << endl;
}

