#pragma once


class Combinatorics
{
public:

	/// Факториал
	static unsigned long long factorial(unsigned short n);

	/// Число сочетаний без повторений (n>=k)
	static unsigned long long combinations(unsigned short k, unsigned short n);

	/// Число размещений без повторений (n>=k)
	static unsigned long long placement(unsigned short k, unsigned short n);

	/// Умножение натуральных чисел от k до n 
	static unsigned long long multiplication(unsigned int k, unsigned int n);
};
