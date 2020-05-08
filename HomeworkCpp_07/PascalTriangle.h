#pragma once
#include <iostream>
#include "Combinatorics.h"
#include "Convert/Convert.h"
#include "CenterConsole.h"

class PascalTriangle
{
private:

	/// ���������� ����� ������������
	int N;

	/// ������ ��������� ������������
	unsigned int** ElementTriangle;

	/// �������� ���������� ������������� ������� ��������� ������������
	void CreateElementTriangle();

	/// �������� ���������� ������������� ������� ��������� ������������
	void DeletelementTriangle();

	/// ���������� ��������� ������������
	void ElementCalculation();

public:	

	/// �������� ����������� �������
	void show(int n);	
};

