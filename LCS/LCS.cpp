#include "LCS.h"
#include <iomanip>
#include <iostream>
using namespace std;

LCS::LCS(const string &x, const string &y) :row(x.size()+1), col(y.size()+1)
{
	str1 = x;
	str2 = y;
	//Ϊmatrix���ٿռ�
	//resize��ά����
	matrix = new int*[row];
	track.resize(row);
	for (int i = 0; i < row; i++)
	{
		matrix[i] = new int[col];
		track[i].resize(col);
	}
	///////////////////////////////////////////
	//��ʼ��matrix��Ԫ�ض�Ϊ0
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			matrix[i][j] = 0;
			track[i][j] = "-";
		}
	}
}


LCS::~LCS()
{
	for (int i = 0; i < str1.size(); i++)
	{
		delete[] matrix[i];
	}
	delete matrix;
}
//���Թ滮������
void LCS::solve()
{
	//��һ��Ԫ�ض���ʼ��Ϊ0
	for (int i = 0; i < row; i++)
		matrix[i][0] = 0; 
	//��һ��Ԫ�ض���ʼ��Ϊ0
	for (int i = 0; i < col; i++)
		matrix[0][i] = 0;

	for (int i = 1; i < row; i++)
	{
		for (int j = 1; j < col; j++)
		{
			if (str1[i-1] == str2[j-1])
			{
				matrix[i][j] = matrix[i - 1][j - 1] + 1;
				track[i][j] = "diag";
			}
			else
			{
				if (matrix[i - 1][j] >= matrix[i][j - 1])
				{
					matrix[i][j] = matrix[i - 1][j];
					track[i][j] = "up";
				}
					
				else
				{
					matrix[i][j] = matrix[i][j - 1];
					track[i][j] = "left";
				}					
			}
		}
	}
}
//��ӡ�����������еĸ����ַ�
void LCS::showLCS()
{
	showLCS(row - 1, col - 1);

	cout << "the LCS is: " << endl;
	for (int i = lcs.size() - 1; i >= 0; i--)
	{
		cout << lcs[i] << " ";
	}
	cout << endl << endl;
}
//��ӡ�����������еĸ����ַ��ĵݹ麯����˽��
void LCS::showLCS(int i, int j)
{
	if (i == 0 || j == 0)
		return;
	else
	{
		if (track[i][j] == "diag")
		{
			lcs.push_back(str1[i - 1]);
			showLCS(i - 1, j - 1);
		}
		else if (track[i][j] == "up")
		{
			showLCS(i - 1, j);
		}
		else
		{
			showLCS(i, j - 1);
		}
	}
}

void LCS::showMatrix()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void LCS::showTrack()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << setw(6) << track[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}