#pragma once
#include "CoffeeMachine.h"

class CoffeeMachineModified : CoffeeMachine
{
private:

	/// Долить воды к кофемашину
	bool addWater;

	/// Долить молока в кофемашшину
	bool addMilk;

	/// Количество чашек Американо
	int numberOfCupsAmericano;

	/// Количество чашек Латте
	int numberOfCupsLatte;

	/// Приготовление напитка Американо
	void Americano() override;

	/// Приготовление напитка Латте
	void Latte() override;

	/// Выбор ответа Да или Нет
	bool SelectionYesNo(std::string text);

	/// Добавить воды в кофемашину
	void AddWater();

	/// Добавить молока в кофемашину
	void AddMilk();

public:

	/// Конструктор
	CoffeeMachineModified();

	/// Запуск программы
	void Run() override;
};

