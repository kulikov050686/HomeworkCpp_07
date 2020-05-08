#include "HomeWork.h"

bool HomeWork::SelectionYesNo(std::string text)
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	std::string items[2] = { "Да", "Нет" };
	MenuController menu(items, 2);

	return menu.selectedMenuItem(text) == 0;
}

std::string HomeWork::RepeatCharacter(std::string str, int n)
{
	std::string temp = "";

	if (n > 0 && str.length() > 0)
	{
		for (int i = 0; i < n; i++)
		{
			temp += str;
		}
	}

	return temp;
}

void HomeWork::Task5()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	std::string strBacteriaCount;
	int bacteriaCount = 0;
	std::string strAmountOfAntibiotic;
	int amountOfAntibiotic = 0;

	std::cout << "Введите количество капель антибиотика: ";
	std::getline(std::cin, strAmountOfAntibiotic);
	std::cout << "Введите количество бактерий: ";
	std::getline(std::cin, strBacteriaCount);
	std::cout << "-----------------------------------------" << std::endl;

	if(Convert::ToInt(strBacteriaCount, bacteriaCount) && Convert::ToInt(strAmountOfAntibiotic, amountOfAntibiotic))
	{
		if (bacteriaCount > 0 && amountOfAntibiotic > 0)
		{
			for (int i = 1; i <= 10; i++)
			{				
				std::cout << "Количество бактерий в чашке: ";

				if (bacteriaCount <= 0)
				{
					std::cout << 0 << std::endl;
					break;
				}
				else
				{
					std::cout << bacteriaCount << std::endl;
				}

				bacteriaCount = bacteriaCount - amountOfAntibiotic * (10 - i);
				bacteriaCount = 2 * bacteriaCount;
			}						
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

void HomeWork::Task6()
{
	const int xmax = 30;
	const int ymax = 10;

	for (int i = 0; i <= ymax; i++)
	{
		std::cout << "|";

		for (int j = 0; j <= xmax; j++)
		{
			if (i == 0 || i == ymax)
			{
				std::cout << "-";
			}
			else
			{
				std::cout << " ";
			}			
		}

		std::cout << "|" << std::endl;
	}
}

void HomeWork::Task7()
{
	const int maxX = 20;
	const int maxY = 10;

	int middleX = maxX / 2;
	int middleY = maxY / 2;

	for (int i = 0; i <= maxY; i++)
	{
		for (int j = 0; j <= maxX; j++)
		{
			if ( j == middleX)
			{
				if (i == 0)
				{
					std::cout << "^";
				}
				else
				{
					if (i == middleY)
					{
						std::cout << "+";
					}
					else
					{
						std::cout << "|";
					}					
				}
			}
			else
			{
				if (i == middleY)
				{
					if (j == maxX)
					{
						std::cout << ">";
					}
					else
					{
						std::cout << "-";
					}
				}
				else
				{
					std::cout << " ";
				}
			}		
		}

		std::cout << std::endl;
	}
}

void HomeWork::Task8()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	std::string name;

	std::cout << "Введите имя: ";	
	std::getline(std::cin, name);
	
	int numberOfSigns = name.length();

	for (int i = 0; i <= 3; i++)
	{
		std::cout << "|";

		for (int j = 0; j <= numberOfSigns + 1; j++)
		{
			if (i == 0 || i == 3)
			{
				std::cout << "-";
			}
			else
			{
				std::cout << " " + name + " ";
				i++;
				break;						
			}
		}

		std::cout << "|" << std::endl;
	}
}

void HomeWork::Task9()
{
	system("cls");	
	setlocale(LC_ALL, "Russian.utf8");
	
	std::cout << "Текст сообщения (не менее 11 символов): ";
		
	setlocale(LC_CTYPE, ".866");	
	std::wstring messageText;
	std::getline(std::wcin, messageText);
		
	int numberOfSigns = messageText.length();

	if (numberOfSigns >= 11)
	{		
		if (SelectionYesNo("Сообщение является важным?"))
		{
			int n = numberOfSigns / 2;
			int k = n / 2;

			for (int i = 0; i <= numberOfSigns; i++)
			{
				if (i < k)
				{
					std::wcout << "~";
				}

				if (k <= i && i < numberOfSigns - k)
				{
					std::wcout << "!";
				}

				if (numberOfSigns - k <= i && i < numberOfSigns)
				{
					std::wcout << "~";
				}
			}			
		}
		else
		{
			int n = numberOfSigns / 2;
			int k = (n + 5) / 2;

			for (int i = 0; i <= numberOfSigns; i++)
			{
				if (i < k)
				{
					std::wcout << "~";
				}

				if (k <= i && i < numberOfSigns - k)
				{
					std::wcout << "!";
				}

				if (numberOfSigns - k <= i && i < numberOfSigns)
				{
					std::wcout << "~";
				}
			}
		}

		std::wcout << std::endl;

		std::wcout << messageText << std::endl;		
	}
	else
	{
		setlocale(LC_ALL, "Russian.utf8");
		std::cout << "Текст сообщения слишком короткий!" << std::endl;
	}	
}

void HomeWork::Task10()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	std::string strNumber;
	int number = 10;
	
	std::cout << "Введите количество строк: ";
	std::getline(std::cin, strNumber);

	if (Convert::ToInt(strNumber, number))
	{
		if (number > 0)
		{
			system("cls");

			for (int i = 0; i < number; i++)
			{
				CenterConsole::Center(RepeatCharacter("#", 2 * i + 1));
			}
		}
		else
		{
			std::cout << "Количество строк не может быть меньше нуля!!!" << std::endl;
		}
	}
	else
	{
		std::cout << "Ошибка ввода данных!!!" << std::endl;
	}	
}

void HomeWork::Task11()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	std::string strNumber;
	int number = 0;

	std::cout << "Введите количество строк теугольника Паскаля: ";
	std::getline(std::cin, strNumber);

	if (Convert::ToInt(strNumber, number))
	{
		if (number > 0)
		{
			system("cls");

			PascalTriangle pascalTriangle;
			pascalTriangle.show(number);
		}
		else
		{
			std::cout << "Количество строк не может быть меньше нуля!!!" << std::endl;
		}
	}
	else
	{
		std::cout << "Ошибка ввода данных!!!" << std::endl;
	}	
}
