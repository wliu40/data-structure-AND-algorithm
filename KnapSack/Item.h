#pragma once
#include <iostream>
using namespace std;
class Item
{
	friend ostream& operator<<(ostream& os, const Item &item);
public:
	Item();
	Item(const int &i, const int &w, const int &v) :
		index(i), weight(w), value(v){};
	~Item();
	int index;
	int weight;
	int value;
};

