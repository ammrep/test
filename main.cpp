
#include <iostream>
using std::cout;
using std::endl;


int main()
{
	setlocale(LC_ALL,"russian");    // работает
	setlocale(LC_ALL,"utf8");    // работает

	cout << "Тест" << endl;
	
	system("pause");
    return 0;
}