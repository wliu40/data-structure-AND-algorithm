#pragma once
class Fibonacci
{
public:
	Fibonacci();
	~Fibonacci();
	int FibRecursive(const int n);//�ݹ���ǰn��
	int FibDP(const int n);//��̬�滮��ǰn��
	int FibArray(const int n); //ʹ�ø���������ǰn��
};

