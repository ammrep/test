#include <iostream>
using std::cout;
using std::endl;

#include "sys/Controller.h"
#include "sys/AppErrorException.h"


int main()
{
	try
	{
	setlocale(LC_ALL,"russian");
	//setlocale(LC_ALL,"utf-8"); 

	Controller contr;
	contr.run();
	
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