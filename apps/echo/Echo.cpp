#include <iostream>
#include <vector>
#include "../../sys/TData.cpp"
using std::cout;
using std::endl;

#include "Echo.h"

Echo::Echo()
{ 

}

void Echo::run(vector<TData> &command)
{
	//cout << "Запущено приложение Echo" << endl;
	cout << command[1].str << endl;    // печатаем строчку
}