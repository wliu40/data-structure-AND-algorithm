#pragma once
#include <vector>
using std::vector;

class EditDistance
{
public:
	EditDistance(const char*, const char*);
	~EditDistance();
	void show();
	void findDis();	
private:
	int min(int a, int b, int c);
	vector<vector<int>> matrix;
	int col;
	int row;
	char *str1; //ºáÌÉ×ÅµÄ×Ö·û´®
	char *str2; //ÊúÌõµÄ×Ö·û´®
};

