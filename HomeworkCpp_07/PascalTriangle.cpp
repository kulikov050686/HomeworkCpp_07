#include "PascalTriangle.h"

void PascalTriangle::CreateElementTriangle()
{
	ElementTriangle = new unsigned int* [N];

	for (int i = 0; i < N; i++)
	{
		ElementTriangle[i] = new unsigned int[N];
	}
}

void PascalTriangle::DeletelementTriangle()
{
	if (ElementTriangle != nullptr)
	{
		for (int i = 0; i < N; i++)
		{
			if (ElementTriangle[i] != nullptr)
			{
				delete[] ElementTriangle[i];
			}
		}

		delete[] ElementTriangle;
	}	
}

void PascalTriangle::ElementCalculation()
{
	for (int k = 0; k < N; k++)
	{
		for (int n = k; n < N; n++)
		{
			ElementTriangle[k][n] = Combinatorics::combinations(k,n);
		}
	}
}

void PascalTriangle::show(int n)
{
	N = n;

	if (N > 0)
	{
		CreateElementTriangle();
		ElementCalculation();

		std::string* str = new std::string[N];

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				str[i] += Convert::ToString(ElementTriangle[j][i]) + " ";
			}			
		}

		for (int i = 0; i < N; i++)
		{
			CenterConsole::Center(str[i]);
		}

		delete[] str;
		DeletelementTriangle();
	}	
}
