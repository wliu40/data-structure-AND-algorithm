#pragma once
class BinomialCoefficients
{
public:
	BinomialCoefficients();
	BinomialCoefficients(unsigned _n, unsigned _k); // ����n��k
	~BinomialCoefficients();
	unsigned long binom_recursive(unsigned n, unsigned k); // �ݹ�caculate C(n, k)
	void binom_dp(); //dynamic programming to caculate C(n, k)
	unsigned long result();//�������Ľ��
private:
	void show();
	const unsigned n;
	const unsigned k;
	unsigned long **bc;//��̬�滮�õ��ĸ�������, �ǣ�n+1�� * ��k+1�� ά
};

