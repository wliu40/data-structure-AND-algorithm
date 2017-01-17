#include "EditDistance.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


EditDistance::EditDistance(const char* s1, const char* s2)
{
	col = strlen(s1) + 1;
	row = strlen(s2) + 1;

	str1 = new char[col + 1];
	strcpy_s(str1, col + 1, s1);
	
	str2 = new char[row + 1];
	strcpy_s(str2, row + 1, s2);

	cout << "str1: " << str1 << endl;
	cout << "str2: " << str2 << endl;

	matrix.resize(row);
	for (int i = 0; i < row; i++)
		matrix[i].resize(col);
}


EditDistance::~EditDistance()
{
	delete[] str1;
	delete[] str2;
}

int EditDistance::min(int a, int b, int c) // �������������������ֵ
{
	int tmp = a < b ? a : b;
	tmp = tmp < c ? tmp : c;
	return tmp;
}

void EditDistance::findDis()
{
	for (int i = 0; i < row; i++) //��д��һ��
	{
		matrix[i][0] = i;
	}
	for (int j = 0; j < col; j++) //��д��һ��
	{
		matrix[0][j] = j;
	}

	int diff = 0;
	for (int i = 1; i < row; i++)
	{
		for (int j = 1; j < col; j++)
		{
			if (str1[j-1] == str2[i-1]) //str1 �����ŵ��ַ���; str2 �������ַ���
				diff = 0;
			else
				diff = 1;
			matrix[i][j] = min(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1, diff + matrix[i - 1][j - 1]);
		}
	}
		
	/*

	int k = 1;
	int diff = 0;
	while (k < row && k < col)
	{		
		for (int j = k; j < col; j++) // ��д��k�У� j��������k������
		{
			diff = str1[j-1] == str2[k-1] ? 0 : 1; //��str1[0]��str2[0]��ʼ�����αȽ������ַ�����j-1��k-1������ĸ
			matrix[k][j] = min(matrix[k - 1][j] + 1, matrix[k][j - 1] + 1, diff + matrix[k - 1][j - 1]);
		}

		for (int i = k+1; i < row; i++) //��д��k��, i��������k������
		{
			diff = str1[k-1] == str2[i-1] ? 0 : 1;//��str1[0]��str2[0]��ʼ�����αȽ������ַ�����i-1��k-1������ĸ
			matrix[i][k] = min(matrix[i - 1][k] + 1, matrix[i][k - 1] + 1, diff + matrix[i - 1][k - 1]);
		}
		k++;
	}

	*/
}

void EditDistance::show()
{
	cout << setw(8) << "";
	for (int i = 0; i < col; i++)
	{

		cout << setw(4) << left << str1[i];
	}

	cout << endl;

	for (int i = 0; i < row; i++)
	{
		if (i == 0)
			cout << setw(4) << "";
		else if (i >= 1)
			cout << setw(4) << left << str2[i - 1];
		for (int j = 0; j < col; j++)
		{
			cout << setw(4) << left << matrix[i][j];
		}
		cout << endl;
	}

}


int main()
{

	EditDistance ed("POLYNOMIAL", "EXPOTENTIAL"); //��exponential�ĳ�polynomial��Ҫ��ô��
	cout << endl;

	ed.findDis();
	ed.show();

	cout << endl;

	EditDistance ed1("KITTEN", "SITTIN");//kitten����ȷƴд��������Ҫ��sittin�ĳ�kitten����Ҫ�ı༭�����Ƕ���
	cout << endl;
	ed1.findDis();
	ed1.show();
	cout << endl;


}