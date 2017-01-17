#include "FloydWarshall.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

FloydWarshall::FloydWarshall()
{
}


FloydWarshall::~FloydWarshall()
{
}

void FloydWarshall::shortestPath(const double (*C)[5], double (*T)[5], const int size) //这里如果写成C[][5]会有Run time error,不知道为什么
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			T[i][j] = C[i][j];
		}

	for (int k = 0; k < size; k++)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				T[i][j] = T[i][j] < (T[i][k] + T[k][j]) ? T[i][j] : (T[i][k] + T[k][j]);
			}
		}
		cout << "\n---------------when k = " << k << "---------------"<< endl;
		show(T, size);
		cout << endl;
	}
}
void FloydWarshall::show(double (*T)[5], const int size) //或者写成T[][5]
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << setw(6) << left << T[i][j] << " ";
		}
		cout << endl;
	}

}

void FloydWarshall::reflexive_transitive_closure(const double(*C)[5], double(*T)[5], const int size) //求传递闭包
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			T[i][j] = C[i][j];
		}

	for (int k = 0; k < size; k++)
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
			{
				if (T[i][j] == 1 || (T[i][k] == 1 && T[k][j] == 1))
					T[i][j] = 1;
				else
					T[i][j] = 0;
			}

}

int main()
{
	const int size = 5;
	//double arr[][5] = { { 0, INFINITY, 15, 3, 6 }, { INFINITY, 0, INFINITY, INFINITY, INFINITY }, 
	//					{ 15, INFINITY, 0, 25, INFINITY }, { 3, INFINITY, 25, 0, 60 }, {6, INFINITY, INFINITY, 60, 0} };

	double arr[][5] = { { 0, 1000, 15, 3, 6 }, { 1000, 0, 1000, 1000, 1000 },
	{ 15, 1000, 0, 25, 1000 }, { 3, 1000, 25, 0, 60 }, { 6, 1000, 1000, 60, 0 } };
	double arr1[][5] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	FloydWarshall fw;
	cout << "原来的邻接矩阵： " << endl;
	fw.show(arr, size);
	fw.shortestPath(arr, arr1, size);
	cout << "\n得到的最短路径矩阵： " << endl;
	fw.show(arr1, size);

	double arr2[][5] = { {1, 0, 1, 0, 0}, {0, 1, 0, 1, 0}, {1, 0, 1, 0, 0}, {0, 1, 0, 1, 1}, {0, 0, 0, 1, 1} };
	double arr3[][5] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	cout << "\n\n原来的传递矩阵： " << endl;
	fw.show(arr2, 5);
	cout << "\n自反传递闭包(transitive closure)矩阵： " << endl; //对角线上的元素是1
	fw.reflexive_transitive_closure(arr2, arr3, 5);
	fw.show(arr3, 5);


}