#include <iostream>
using std::cout;
using std::endl;
#include "sys/Controller.h"


int main()
{
	setlocale(LC_ALL,"russian");    // работает
	setlocale(LC_ALL,"utf8");    // работает

	Controller contr;
	contr.run();
	
	system("pause");
    return 0;
}