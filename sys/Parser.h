﻿/**
* Класс Parser принимает на вход строку, полученную от пользователя,
* проверяет допустима ли такая строка, разбивает её на части, и возвращает
* контроллеру упорядоченную информацию
*/
#include <iostream>
#include <string>
using std::cout;
using std::endl;
/**
* Класс Parser - класс, который вызывается контроллером. Контроллер передаёт ему строку
* команды, а он парсит её, проверяет на ошибки(пока не реализовано) и отдаёт контроллеру
* упорядоченные данные
*/
using std::string;

class Parser {

public:

Parser();
//~Parser();

/**
* Функция, которая принимает строку команды и возвращает вектор с данными(проблема с 
* возвратом вектора) 
*/
void parse(string);
};