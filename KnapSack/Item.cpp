#include "Item.h"
#include <iostream>
#include <iomanip>

using namespace std;

Item::Item()
{
}


Item::~Item()
{
}

ostream& operator<<(ostream& os, const Item & item)
{
	os << setw(10) << item.index;
	os << setw(10) << item.weight;
	os << setw(10) << item.value;
	return os;
}
