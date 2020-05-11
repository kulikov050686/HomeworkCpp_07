#include "CoffeeMachineModified.h"

void CoffeeMachineModified::Americano()
{
	setlocale(LC_ALL, "Russian.utf8");

	if (amountOfWater >= waterAmericano)
	{
		std::cout << "Ваш напиток готов!!!" << std::endl;

		amountOfWater -= waterAmericano;
		numberOfCupsAmericano++;
	}
	else
	{
		std::cout << "В кофемашине не хватает воды!!!" << std::endl;
		addWater = true;
	}

	if (amountOfWater <= 0)
	{
		amountOfWater = 0;
	}

	std::cout << "В кофемашине: " << amountOfWater << " мл воды" << std::endl;
	std::cout << "В кофемашине: " << amountOfMilk << " мл молока" << std::endl;
}

void CoffeeMachineModified::Latte()
{
	setlocale(LC_ALL, "Russian.utf8");

	if (amountOfWater >= waterLatte)
	{
		if (amountOfMilk >= milkLatte)
		{
			std::cout << "Ваш напиток готов!!!" << std::endl;

			amountOfMilk -= milkLatte;
			amountOfWater -= waterLatte;
			numberOfCupsLatte++;
		}
		else
		{
			std::cout << "В кофемашине не хватает молока!!!" << std::endl;
			addMilk = true;
		}
	}
	else
	{
		std::cout << "В кофемашине не хватает воды!!!" << std::endl;
		addWater = true;
	}

	if (amountOfWater <= 0)
	{
		amountOfWater = 0;
	}

	if (amountOfMilk <= 0)
	{
		amountOfMilk = 0;
	}

	std::cout << "В кофемашине: " << amountOfWater << " мл воды" << std::endl;
	std::cout << "В кофемашине: " << amountOfMilk << " мл молока" << std::endl;
}

bool CoffeeMachineModified::SelectionYesNo(std::string text)
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	std::string items[2] = { "Да", "Нет" };
	MenuController menu(items, 2);

	return menu.selectedMenuItem(text) == 0;
}

void CoffeeMachineModified::AddWater()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	if (SelectionYesNo("В кофемашине не хватает воды, желаете её добавить?"))
	{
		std::string strWater;
		int water = 0;
		bool output = false;

		while (!output)
		{
			std::cout << "Введите количество доливаемой воды в кофемашину мл: ";
			std::getline(std::cin, strWater);

			if (Convert::ToInt(strWater, water))
			{
				if (addWater > 0)
				{
					amountOfWater += water;
					output = true;
				}
				else
				{
					std::cout << "Ошибка ввода данных!!!" << std::endl;
				}
			}
			else
			{
				std::cout << "Ошибка ввода данных!!!" << std::endl;
			}
		}
	}
}

void CoffeeMachineModified::AddMilk()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	if (SelectionYesNo("В кофемашине не хватает молока, желаете его добавить?"))
	{
		std::string strMilk;
		int milk = 0;
		bool output = false;

		while (!output)
		{
			std::cout << "Введите количество доливаемого молока в кофемашину мл: ";
			std::getline(std::cin, strMilk);

			if (Convert::ToInt(strMilk, milk))
			{
				if (milk > 0)
				{
					amountOfMilk += milk;
					output = true;
				}
				else
				{
					std::cout << "Ошибка ввода данных!!!" << std::endl;
				}
			}
			else
			{
				std::cout << "Ошибка ввода данных!!!" << std::endl;
			}
		}
	}
}

CoffeeMachineModified::CoffeeMachineModified()
{	
	addWater = false;
	addMilk = false;
	numberOfCupsAmericano = 0;
	numberOfCupsLatte = 0;
}

void CoffeeMachineModified::Run()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	std::string items[3] = { "Американо", "Латте", "Выход" };
	MenuController menu(items, 3);

	if (RefuelingCoffeeMachine())
	{
		while (!exit)
		{
			switch (menu.selectedMenuItem("Выберите вид кофе: "))
			{
			case 0:
				Americano();
				_getch();
				break;
			case 1:
				Latte();
				_getch();
				break;
			case 2:
				exit = true;
				break;
			}

			if (addWater)
			{
				AddWater();
				std::cout << "В кофемашине: " << amountOfWater << " мл воды" << std::endl;
				std::cout << "В кофемашине: " << amountOfMilk << " мл молока" << std::endl;
				addWater = false;
				_getch();
			}

			if (addMilk)
			{
				AddMilk();
				std::cout << "В кофемашине: " << amountOfWater << " мл воды" << std::endl;
				std::cout << "В кофемашине: " << amountOfMilk << " мл молока" << std::endl;
				addMilk = false;
				_getch();
			}

			if (exit)
			{
				std::cout << "Кофемашиной было приготовленно: " << numberOfCupsAmericano << " чашек Американо" << std::endl;
				std::cout << "Кофемашиной было приготовленно: " << numberOfCupsLatte << " чашек Латте" << std::endl;
				std::cout << "В кофемашине осталось: " << amountOfWater << " мл воды" << std::endl;
				std::cout << "В кофемашине осталось: " << amountOfMilk << " мл молока" << std::endl;
				_getch();
			}
		}
	}
}
