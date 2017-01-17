#pragma once

/*
�ั���ı������⣺
����������һ������Ϊcapacity�ı�������ô���ǽ���һ��һά����k, k[w]��ʾ������������Ϊwʱ�������ڿ��ܵ�����ֵ�ĺ͡�
�ö�̬�滮�ķ�������С����Ľ��֧�ִ���������ģʽ����w=0��capacity����������k.
���仰˵�����ҵ�k[w]��ǰ�������Ѿ��ҵ���k[0]��k[w-1]��ֵ��

�㷨����ʱ��:��Ϊ����ÿ����������Ҫ���μ��n����Ʒ������һ��������ʱ��O(capacity*n);

****************************   *���Ĵ���*   ****************************

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
	void solver_repetation();//�����Զั����0-1��������
	void solver_repetation_1();//�����Զั����0-1��������
	void showItemsInSack();
	void solver_0_1();//��ⵥ������0-1��������
	void showMatrix();//�������е�״̬����i, w��.i��ʾǰiǰ��Ʒ��w��ʾ�����Ŀ����ɵ��������, matrix[i][w]��ʾǰi����Ʒװ��ʣ�����Ϊj�ı������ܴﵽ������ֵ
private:
	const unsigned Knapsack_Capacity;//�����Ŀ����ɵ��������
	vector<Item> items;//����ѡ����Ʒ

	//������k, k[i]��ʾ��knapsack������Ϊiʱ���ܵõ�������ֵ��
	//��ΪҪ������0��Knapsack_Capacity������k[i],����Ҫresize(Knapsack_Capacity + 1);
	vector<int> K;//���ڶั����0-1�������⣬ K[w]��ʾ������������wʱ�� �����װ�µ�������Ʒ������ֵ��

	vector<vector<Item>> itemsInSack;//���ڶั����0-1�������⣬���ﶼ����Щ��Ʒ��

	int **matrix;//���ڵ�������0-1�������⣬ matrix[i][w]��ʾǰi����Ʒ������������Ϊwʱ����װ�µ�����ֵ
	int size_of_items; //how many items are there?�����ʵ����items.size();
	//int col;


};

