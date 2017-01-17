#pragma once
/*
寻找最长公共子序列， 动态规划。
详细内容见：《算法导论》, p.209
*/
#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector; 
using std::cout;
using std::endl;

class LCS
{

public:
	LCS(const string &s1, const string &s2); //传入两个字符串s1,s2.要求出最长公共子序列的长度和内容
	~LCS();//delete 对象内的动态分配的矩阵数组

	void solve();//线性规划求解过程
	void showLCS();//打印出公共子序列的各个字符
	void showMatrix();//打印出状态矩阵
	void showTrack();//打印出辅助二维向量矩阵
	
private:
	//假设要寻找str1和str2的LCS
	string str1;
	string str2;
	//假设找到的最长公共子序列是lcs
	vector<char> lcs;
	//要建立一个状态转移矩阵matrix, 用于储存lcs的长度
	int row;
	int col;
	int **matrix;
	//一个辅助的二维vector，用于找出lcs内的字符
	vector< vector<string> > track;
	//递归调用的私有函数
	void showLCS(int x, int y);
};


