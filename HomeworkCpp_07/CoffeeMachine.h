#pragma once
#include <iostream>
#include <string>
#include "Menu/MenuController.h"
#include "Convert/Convert.h"

class CoffeeMachine
{
protected:
	/// Количество воды необходимое для приготовления Американо
	const int waterAmericano = 300;

	/// Количество воды необходимое для приготовления Латте
	const int waterLatte = 30;

	/// Количество молока необходимое для приготовления Латте
	const int milkLatte = 270;

	/// Завершение программы
	bool exit;

	/// Количество воды в кофемашине
	int amountOfWater;

	/// Количество молока в кофемашине
	int amountOfMilk;

	/// Приготовление напитка Американо
	virtual void Americano();

	/// Приготовление напитка Латте
	virtual void Latte();

	/// Первоначальная заправка кофемашины
	virtual bool RefuelingCoffeeMachine();
	
public:

	/// Конструктор
	CoffeeMachine();

	/// Запуск программы
	virtual void Run();
};
