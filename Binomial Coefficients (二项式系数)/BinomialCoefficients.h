#pragma once
class BinomialCoefficients
{
public:
	BinomialCoefficients();
	BinomialCoefficients(unsigned _n, unsigned _k); // 输入n和k
	~BinomialCoefficients();
	unsigned long binom_recursive(unsigned n, unsigned k); // 递归caculate C(n, k)
	void binom_dp(); //dynamic programming to caculate C(n, k)
	unsigned long result();//返回最后的结果
private:
	void show();
	const unsigned n;
	const unsigned k;
	unsigned long **bc;//动态规划用到的辅助矩阵, 是（n+1） * （k+1） 维
};

