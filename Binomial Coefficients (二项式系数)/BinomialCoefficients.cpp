#include "BinomialCoefficients.h"
#include <iostream>
using namespace std;

BinomialCoefficients::BinomialCoefficients(unsigned _n, unsigned _k) :n(_n + 1), k(_k + 1)
{
	//为bc开辟空间
	bc = new unsigned long*[n];
	for (int i = 0; i < n; i++)
	{
		bc[i] = new unsigned long[k];
	}
	// 初始化bc
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			bc[i][j] = 0;
		}
	}
}

BinomialCoefficients::~BinomialCoefficients()
{
	for (int i = 0; i < n; i++)
	{
		delete[] bc[i];
		//cout << "deleting bc[" << i << "]" << endl;
	}
	delete[] bc;
	//cout << "deletiong done" << endl;
}
//Asymptotic time and space estimates ?
unsigned long BinomialCoefficients::binom_recursive(unsigned n, unsigned k)// 递归caculate C(n, k)
{
	if (k == 0 || k == n)
		return 1;
	else
		return binom_recursive(n - 1, k - 1) + binom_recursive(n - 1, k);
}
//Asymptotic time O(n^2) and O(n^2) space
void BinomialCoefficients::binom_dp() //dynamic programming to caculate C(n, k)
{
	for (int i = 0; i < k; i++) //将对角线上的元素设置为1 （不是严格对角线，因为这不是一个方阵）
	{
		bc[i][i] = 1;
	}
	for (int i = 0; i < n; i++)//将第一列的元素设置为1
	{
		bc[i][0] = 1;
	}
	show();
	for (int i = 2; i < n; i++) //依次设置每行的值
	{
		for (int j = 1; j < k; j++)
		{
			bc[i][j] = bc[i-1][j-1] + bc[i-1][j];
		}
		cout << "---------------------------------------" << endl;
		show();
	}	
}
//返回最后的结果
unsigned long BinomialCoefficients::result()
{
	return bc[n-1][k-1];
}
//打印辅助矩阵bc
void BinomialCoefficients::show()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cout << bc[i][j] << " ";
		}
		cout << endl;
	}

}
int main()
{
	BinomialCoefficients bc(7, 3);
	bc.binom_dp();

	cout << "the result is(by dynamic programming): ";
	cout << bc.result() << endl;

	cout << "the result is(by resursion): ";
	cout << bc.binom_recursive(7,3) << endl;
}