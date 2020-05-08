#pragma once


class Combinatorics
{
public:

	/// ���������
	static unsigned long long factorial(unsigned short n);

	/// ����� ��������� ��� ���������� (n>=k)
	static unsigned long long combinations(unsigned short k, unsigned short n);

	/// ����� ���������� ��� ���������� (n>=k)
	static unsigned long long placement(unsigned short k, unsigned short n);

	/// ��������� ����������� ����� �� k �� n 
	static unsigned long long multiplication(unsigned int k, unsigned int n);
};
