#pragma once

#include <limits>
double myinf = std::numeric_limits<double>::infinity();


class FloydWarshall
{
public:
	static unsigned size;
	FloydWarshall();
	~FloydWarshall();
	void shortestPath(const double (*C)[5], double (*T)[5], const int size); // �����·��
	void show(double T[][5], const int size);
	void reflexive_transitive_closure(const double(*C)[5], double(*T)[5], const int size); //�󴫵ݱհ�
};

