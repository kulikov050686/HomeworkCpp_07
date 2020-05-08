#pragma once
#include <iostream>
#include "Combinatorics.h"
#include "Convert/Convert.h"
#include "CenterConsole.h"

class PascalTriangle
{
private:

	/// Количество строк треугольника
	int N;

	/// Массив элементов треугольника
	unsigned int** ElementTriangle;

	/// Создание двумерного динамического массива элементов треугольника
	void CreateElementTriangle();

	/// Удаление двумерного динамического массива элементов треугольника
	void DeletelementTriangle();

	/// Вычисление элементов треугольника
	void ElementCalculation();

public:	

	/// Показать треугольник Паскаля
	void show(int n);	
};

