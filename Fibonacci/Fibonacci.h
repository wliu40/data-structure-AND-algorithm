#pragma once
class Fibonacci
{
public:
	Fibonacci();
	~Fibonacci();
	int FibRecursive(const int n);//递归求前n项
	int FibDP(const int n);//动态规划求前n项
	int FibArray(const int n); //使用辅助数列求前n项
};

