#include "KnapSack.h"
#include <iostream>
#include <iomanip>

using namespace std;

KnapSack::KnapSack(const vector<Item> &v, int cap) : size_of_items(v.size()), Knapsack_Capacity(cap)
{
	//capacity = cap;
	items = v;
	//K.resize(cap+1);
//	size_of_items = cap + 1;
	K.resize(Knapsack_Capacity + 1);
	itemsInSack.resize(Knapsack_Capacity + 1);

	/////////////////////////////////////
	//为matrix创建内存
	matrix = new int*[size_of_items + 1];
	for (int i = 0; i < size_of_items + 1; i++)
	{
		matrix[i] = new int[Knapsack_Capacity + 1];		
	}
	////////////////////////////////////
	//matrix所有元素初始化为0
	for (int i = 0; i < size_of_items + 1; i++)
		for (int j = 0; j < Knapsack_Capacity + 1; j++)
			matrix[i][j] = 0;
}

KnapSack::~KnapSack()
{
	for (int i = 0; i < size_of_items + 1; i++)
		delete[] matrix[i];
//	delete matrix;
}
int KnapSack::max(const int a, const int b)
{
	return a > b ? a : b;
}
void KnapSack::solver_repetation()//多副本问题
{
	for (int w = 0; w <= Knapsack_Capacity; w++)	// 从小到大建立问题的解： 依次找到K[w]的值，直至capacity
	{
		K[w] = 0;
		for (auto &item : items) //一共有n个item
		{
			if (item.weight <= w) // 对于每个重量小于等于w的物品都要"拿出来"试试看
			{
				K[w] = max(K[w], K[w - item.weight] + item.value);//是包里现有的物品值钱，还是某个物品，加上去掉这个物品的重量的价值，的和更值钱？
			}
		}
	}
}

void KnapSack::solver_repetation_1()
{
	for (int w = 0; w <= Knapsack_Capacity; w++)
	{
		Item x;
		K[w] = 0;
		for (auto &item : items)
		{
			if (item.weight <= w)
			{
				if (K[w] < K[w - item.weight] + item.value)
				{
					K[w] = K[w - item.weight] + item.value;
					x = item;
					itemsInSack[w] = itemsInSack[w - item.weight];
					itemsInSack[w].push_back(x);
				}
			}
		}
	}
}

void KnapSack::solver_0_1()//单副本问题
{
	//for (int i = 0; i < size_of_items + 1; i++)
	//	matrix[i][0] = 0;
	//for (int j = 0; j < Knapsack_Capacity + 1; j++)
	//	matrix[0][j] = 0;

	for (int i = 1; i < size_of_items + 1; i++)
	{
		for (int w = 1; w < Knapsack_Capacity + 1; w++)
		{
			cout << "对于前" << i << "个物品, 背包重量为" << w << "时" << endl;
			if (items[i - 1].weight > w)
			{
				cout << "如果第" << i - 1 << "物品的重量(" << items[i - 1].weight << ")大于 " << w << ", matrix[" << i << "][" << w << "] = matrix[" << i-1 <<"][" << w << "]" << endl;

				matrix[i][w] = matrix[i - 1][w];
			}
				
			else
			{
				cout << "如果第" << i - 1 << "物品的重量(" << items[i - 1].weight << ")小于等于 " << w << ",";
				cout << "matrix[" << i << "][" << w << "] = ";
				cout << "max(matrix[" << i - 1 << "][" << w << "], matrix[" << i - 1 << "][" << w - items[i - 1].weight << "]+" << items[i - 1].value << ");";

				matrix[i][w] = max(matrix[i - 1][w], matrix[i - 1][w - items[i - 1].weight] + items[i - 1].value);
			}
	
			cout << "\nmatrix now is " << endl;
			showMatrix();
		}
		//showMatrix();
	}
}
void KnapSack::showMatrix()
{
	for (int i = 0; i < size_of_items + 1; i++)
	{
		for (int j = 0; j < Knapsack_Capacity + 1; j++)
		{
			cout << setw(3) << matrix[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
void KnapSack::showItemsInSack()
{
	cout << setw(10) << "index";
	cout << setw(10) << "weight";
	cout << setw(10) << "value" << endl;
	for (int i = 0; i < items.size(); i++)
	{
		cout << items[i] << endl;
	}
	cout << "-------------------------------------------------" << endl;
	for (int i = 0; i <= Knapsack_Capacity; i++)
	{
		cout << setw(10) << right << "weight = " << setw(2) << right << i;
		cout << setw(15) << "max value is: " << setw(3) << right << K[i] << ",  includes(index): ";
		for (int j = 0; j < itemsInSack[i].size(); j++)
		{
			cout << itemsInSack[i][j].index << " ";
		}
		cout << endl;
	}

}