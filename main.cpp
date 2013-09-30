#include <iostream>
using std::cout;
using std::endl;

#include "sys/Controller.h"
#include "sys/AppErrorException.h"
#include "sys/ControllerErrorException.h"


int main()
{
	try
	{
		try{
	setlocale(LC_ALL,"russian");
	//setlocale(LC_ALL,"utf-8"); 

	Controller contr;
	contr.run();
		}
		catch (ControllerErrorException &ControllerErrorException)
		{
			cout << "Обнаружена ошибка: " << ControllerErrorException.what() << endl; 
		}
	}
	catch (AppErrorException &AppErrorException)
	{
		cout << "Обнаружена ошибка: " << AppErrorException.what() << endl; 
	}

	#ifdef _WIN32
		system("pause");
	#endif
		
    return 0;
}