#include "CoffeeMachine.h"

void CoffeeMachine::Americano()
{
	setlocale(LC_ALL, "Russian.utf8");

	if (amountOfWater >= waterAmericano)
	{
		std::cout << "Ваш напиток готов!!!" << std::endl;

		amountOfWater -= waterAmericano;
	}
	else
	{
		std::cout << "В кофемашине не хватает воды!!!" << std::endl;		
	}

	if (amountOfWater <= 0)
	{
		amountOfWater = 0;
	}

	std::cout << "В кофемашине: " << amountOfWater << " мл воды" << std::endl;
	std::cout << "В кофемашине: " << amountOfMilk << " мл молока" << std::endl;
}

void CoffeeMachine::Latte()
{
	setlocale(LC_ALL, "Russian.utf8");

	if (amountOfWater >= waterLatte)
	{
		if (amountOfMilk >= milkLatte)
		{
			std::cout << "Ваш напиток готов!!!" << std::endl;

			amountOfMilk -= milkLatte;
			amountOfWater -= waterLatte;
		}
		else
		{
			std::cout << "В кофемашине не хватает молока!!!" << std::endl;			
		}
	}
	else
	{
		std::cout << "В кофемашине не хватает воды!!!" << std::endl;		
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

bool CoffeeMachine::RefuelingCoffeeMachine()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	std::string strAmountOfWater;
	std::string strAmountOfMilk;

	std::cout << "Введите количество воды в кофемашине мл: ";
	std::getline(std::cin, strAmountOfWater);
	std::cout << "Введите количество молока в кофемашине мл: ";
	std::getline(std::cin, strAmountOfMilk);

	

	if (Convert::ToInt(strAmountOfWater, amountOfWater) && Convert::ToInt(strAmountOfMilk, amountOfMilk))
	{
		if (amountOfMilk >= 0 && amountOfWater >= 0)
		{
			return true;
		}
		else
		{
			std::cout << "Ошибка ввода данных!!!" << std::endl;
			return false;
		}
	}
	
	std::cout << "Ошибка ввода данных!!!" << std::endl;
	return false;	
}

CoffeeMachine::CoffeeMachine()
{
	exit = false;	
	amountOfWater = 0;
	amountOfMilk = 0;
}

void CoffeeMachine::Run()
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
		}					
	}	
}
