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
	for (size_t i = 0; i < command.size(); i++) 
		if (command.at(i).type == PARAMETER)
			cout << command.at(i).str << " ";
	cout << endl;
}