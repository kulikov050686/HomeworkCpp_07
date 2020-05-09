#include "HomeWork.h"

bool HomeWork::SelectionYesNo(std::string text)
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	std::string items[2] = { "Да", "Нет" };
	MenuController menu(items, 2);

	return menu.selectedMenuItem(text) == 0;
}

int HomeWork::Random(int min, int max)
{
	std::random_device rd;
	std::mt19937 mersenne(rd());

	return min + mersenne() % (max - min);
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

void HomeWork::Task3()
{
}

void HomeWork::Task4()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	int positionX = Random(0, 16);
	int positionY = Random(0, 21);
	bool exit = false;
	std::string key;

	std::cout << "Программа управления марсоходом." << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	std::cout << "Команды:" << std::endl;
	std::cout << "W - движение на север" << std::endl;
	std::cout << "S - движение на юг" << std::endl;
	std::cout << "A - движение на запад" << std::endl;
	std::cout << "D - движение на восток" << std::endl;
	std::cout << "С - выход из программы" << std::endl;
	std::cout << "---------------------------------------" << std::endl;

	while (!exit)
	{
		std::cout << "Марсоход находится на позиции (" << positionX << "," << positionY << ") введите команду :";
		std::getline(std::cin, key);

		if (key == "w" || key == "W")
		{
			if (positionY < 20)
			{
				positionY++;
			}
		}
		else if (key == "s" || key == "S")
		{
			if (positionY > 0)
			{
				positionY--;
			}
		}
		else if (key == "a" || key == "A")
		{
			if (positionX > 0)
			{
				positionX--;
			}
		}
		else if (key == "d" || key == "D")
		{
			if (positionX < 15)
			{
				positionX++;
			}
		}
		else if (key == "c" || key == "C")
		{
			exit = true;
		}
		else
		{
			std::cout << "Такой команды не существует!!!" << std::endl;
		}
	}
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
				bacteriaCount = bacteriaCount - amountOfAntibiotic * (10 - i);
				bacteriaCount = 2 * bacteriaCount;

				std::cout << "Количество бактерий в чашке: ";

				if (bacteriaCount <= 0)
				{
					bacteriaCount = 0;
					std::cout << bacteriaCount << " в конце " << i << "-го часа" << std::endl;
					break;
				}
				else
				{
					std::cout << bacteriaCount << " в конце " << i << "-го часа" << std::endl;
				}			
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
