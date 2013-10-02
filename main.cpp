#include <iostream>
using std::cout;
using std::endl;

#include "sys/Controller.h"
#include "sys/ControllerErrorException.h"


int main()
{
	try
	{
	setlocale(LC_ALL,"russian");
	//setlocale(LC_ALL,"utf-8"); 

	Controller contr;
	contr.run();
	}
	catch (ControllerErrorException &ControllerErrorException)
	{
		cout << "Обнаружена ошибка: " << ControllerErrorException.what() << endl; 
	}

	#ifdef _WIN32
		system("pause");
	#endif
		
    return 0;
}