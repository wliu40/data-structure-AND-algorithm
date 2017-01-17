#pragma once

/*
多副本的背包问题：
假设我们有一个容量为capacity的背包，那么我们建立一个一维向量k, k[w]表示当背包的容量为w时，背包内可能的最大的值的和。
用动态规划的方法，以小问题的解答支持大问题求解的模式，从w=0到capacity建立起向量k.
换句话说，在找到k[w]以前，我们已经找到了k[0]到k[w-1]的值。

算法运行时间:因为对于每个重量，都要依次检查n个物品，所以一共的运行时间O(capacity*n);

****************************   *核心代码*   ****************************

for(int w = 0; w < capacity; w++)
{
	k[w] = 0;
	for(auto &item: items)
	{
		if(item.weight < w)
		{
			k[w] = max(k[w], k[w - item.weight] + item.value);
		}
	}
}

***********************************************************************
*/
#include "Item.h"
#include <vector>
using std::vector;
class KnapSack
{
public:
	KnapSack();
	KnapSack(const vector<Item> &v, int cap);//construct a object by inputing the items vector, and the capacity of the sack
	~KnapSack();
	int max(const int a, const int b);//helper function
	void solver_repetation();//求解可以多副本的0-1背包问题
	void solver_repetation_1();//求解可以多副本的0-1背包问题
	void showItemsInSack();
	void solver_0_1();//求解单副本的0-1背包问题
	void showMatrix();//求解过程中的状态矩阵（i, w）.i表示前i前物品，w表示背包的可容纳的最大重量, matrix[i][w]表示前i个物品装到剩余体积为j的背包里能达到的最大价值
private:
	const unsigned Knapsack_Capacity;//背包的可容纳的最大重量
	vector<Item> items;//待挑选的物品

	//即向量k, k[i]表示当knapsack的容量为i时，能得到的最大价值，
	//因为要建立从0到Knapsack_Capacity的所有k[i],所以要resize(Knapsack_Capacity + 1);
	vector<int> K;//对于多副本的0-1背包问题， K[w]表示当背包容量是w时， 包里可装下的所有物品的最大价值。

	vector<vector<Item>> itemsInSack;//对于多副本的0-1背包问题，包里都有哪些物品？

	int **matrix;//对于单副本的0-1背包问题， matrix[i][w]表示前i个物品，当背包容量为w时，可装下的最大价值
	int size_of_items; //how many items are there?这个其实等于items.size();
	//int col;


};

