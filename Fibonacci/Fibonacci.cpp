#include "Fibonacci.h"
#include <vector>
#include <iostream>
using namespace std;

Fibonacci::Fibonacci()
{	
}


Fibonacci::~Fibonacci()
{
}

int Fibonacci::FibRecursive(const int n) //递归
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	else
		return FibRecursive(n - 1) + FibRecursive(n - 2);
}

int Fibonacci::FibArray(const int n) //使用辅助数列
{

	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	vector<int> array;
	array.resize(n);
	array[0] = 1;
	array[1] = 1;

	for (int i = 2; i < n; i++)
	{
		array.at(i) = array.at(i - 2) + array.at(i - 1);
	}
	return array.at(n-1);

}

int Fibonacci::FibDP(const int n)//动态规划
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	else
	{
		int back1, back2, cur;
		back2 = 0;
		back1 = 1;
		cur = 0;
		for (int i = 2; i <= n; i++)
		{
			cur = back1 + back2;
			back2 = back1;
			back1 = cur;
		}
		return cur;
	}
}

int main()
{
	Fibonacci fb;
	int size = 15;

	cout << "use array: " << endl;
	for(int i = 0; i < size; i++)
	{
		cout << fb.FibArray(i) << " ";
	}

	cout << "\n\nby recursive: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << fb.FibRecursive(i) << " ";
	}

	cout << "\n\ndynamic programming: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << fb.FibDP(i) << " ";
	}

	cout << endl;

}