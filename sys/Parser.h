﻿/**
* Класс Parser - класс, который вызывается контроллером. Контроллер передаёт ему строку
* команды, а он парсит её, проверяет на ошибки(пока не реализовано) и отдаёт контроллеру
* упорядоченные данные
*/

#ifndef PARSER_H
#define PARSER_H

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "TData.cpp"

class Parser {
public:
	Parser();
	//~Parser();

	/**
	* Функция, которая принимает строку команды и возвращает вектор с данными(проблема с 
	* возвратом вектора) 
	*/
	vector<TData> parse(string);
private:
	vector<TData> getTokens(string);
};

#endif
