#pragma once
#include <iostream>
#include <string>
#include <clocale>
#include "Convert/Convert.h"
#include"Menu/MenuController.h"
#include "PascalTriangle.h"
#include "CenterConsole.h"

class HomeWork
{
private:

	/// Выбор ответа Да или Нет
	bool SelectionYesNo(std::string text);

	/// Получить строку из n одинаковых строк
	std::string RepeatCharacter(std::string str, int n);

public:

	// Задача 1
	void Task1();

	// Задача 2
	void Task2();

	// Задача 3
	void Task3();

	// Задача 4
	void Task4();

	// Задача 5
	void Task5();

	// Задача 6
	void Task6();

	// Задача 7
	void Task7();

	// Задача 8
	void Task8();

	// Задача 9
	void Task9();

	// Задача 10
	void Task10();

	// задача 11
	void Task11();
};

