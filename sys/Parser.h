/**
* Класс Parser принимает на вход строку, полученную от пользователя,
* проверяет допустима ли такая строка, разбивает её на части, и возвращает
* контроллеру упорядоченную информацию
*/
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Parser {

public:

Parser();
//~Parser();

void parse(string);

};