#pragma once
/*
Ѱ������������У� ��̬�滮��
��ϸ���ݼ������㷨���ۡ�, p.209
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
	LCS(const string &s1, const string &s2); //���������ַ���s1,s2.Ҫ�������������еĳ��Ⱥ�����
	~LCS();//delete �����ڵĶ�̬����ľ�������

	void solve();//���Թ滮������
	void showLCS();//��ӡ�����������еĸ����ַ�
	void showMatrix();//��ӡ��״̬����
	void showTrack();//��ӡ��������ά��������
	
private:
	//����ҪѰ��str1��str2��LCS
	string str1;
	string str2;
	//�����ҵ����������������lcs
	vector<char> lcs;
	//Ҫ����һ��״̬ת�ƾ���matrix, ���ڴ���lcs�ĳ���
	int row;
	int col;
	int **matrix;
	//һ�������Ķ�άvector�������ҳ�lcs�ڵ��ַ�
	vector< vector<string> > track;
	//�ݹ���õ�˽�к���
	void showLCS(int x, int y);
};


