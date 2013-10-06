#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

#include <vector>
using std::vector;

#include <fstream>
using std::ifstream;

#include <algorithm>
using std::reverse;

#include "Cd.h"
#include "../../sys/TData.cpp"
#include "../../sys/AppErrorException.h"

Cd::Cd() {}

void Cd::run(vector<TData> command)
{
	cout << "Приложение Cd запущено!" << endl;
}