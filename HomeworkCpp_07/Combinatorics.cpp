#include "Combinatorics.h"

unsigned long long Combinatorics::factorial(unsigned short n)
{
	if (n == 0 || n == 1)
	{
		return 1;
	}
	
	unsigned long long factorial = 1;

	if (n > 1)
	{
		for (unsigned short i = 2; i <= n; i++)
		{
			factorial = factorial * i;
		}
	}

	return factorial;
}

unsigned long long Combinatorics::combinations(unsigned short k, unsigned short n)
{
	if (n >= k)
	{
		return factorial(n) / (factorial(n - k) * factorial(k));
	}

	return 0;
}

unsigned long long Combinatorics::placement(unsigned short k, unsigned short n)
{
	if (n >= k)
	{
		return factorial(n) / factorial(n - k);
	}

	return 0;
}

unsigned long long Combinatorics::multiplication(unsigned int k, unsigned int n)
{
	unsigned long long mult = 1;

	if (n >= k)
	{
		for (unsigned short i = k; i <= n; i++)
		{
			mult = mult * i;
		}

		return mult;
	}

	return 0;
}
