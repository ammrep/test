#include <iostream>
using std::cout;
using std::endl;
#include "sys/Controller.h"


int main()
{
	setlocale(LC_ALL,"russian");
	//setlocale(LC_ALL,"utf-8"); 

	Controller contr;
	contr.run();
	
	system("pause");
    return 0;
}