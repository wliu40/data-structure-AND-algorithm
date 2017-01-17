#include <iostream>
#include <vector>
#include <string>
using namespace std;

void  dfs(vector<vector<char>>& grid, vector<vector<bool>>& marked, int row, int col, int i, int j);
int numIslands(vector<vector<char>>& grid);
vector<vector<char>> initGrid(vector<string> &vec);

template <class T>
void show(vector <vector <T>> &data);
bool isValid(int row, int col, int i, int j);
int main()
{
	//vector<string> str = {"11000", "11000", "00100", "00011"};
	//vector<string>str = {"10"};
	vector <string> str = { "111", "010", "111" };
	vector<vector<char>> grid = initGrid(str);
	//show(grid);

	//cout << endl;
	cout << numIslands(grid) << endl;


}
bool isValid(int row, int col, int i, int j)
{
	if (i < row && i >= 0 && j >= 0 && j < col)
		return true;
	else
		return false;
}

void dfs(vector<vector<char>>& grid, vector<vector<bool>>& marked, int row, int col, int i, int j)
{

	marked[i][j] = true;// this point was visited

	//if the neighbor points have a valid index[i][j] and grid value is '1' and the point has not been visited
	if (isValid(row, col, i - 1, j) && grid[i - 1][j] == '1' && marked[i - 1][j] == false)
		dfs(grid, marked, row, col, i - 1, j);

	if (isValid(row, col, i + 1, j) && grid[i + 1][j] == '1' && marked[i + 1][j] == false)
		dfs(grid, marked, row, col, i + 1, j);

	if (isValid(row, col, i, j - 1) && grid[i][j - 1] == '1' && marked[i][j - 1] == false)
		dfs(grid, marked, row, col, i, j - 1);

	if (isValid(row, col, i, j + 1) && grid[i][j + 1] == '1' && marked[i][j + 1] == false)
		dfs(grid, marked, row, col, i, j + 1);
}

int numIslands(vector<vector<char>>& grid) {
	vector< vector<bool> > marked;
	int row = grid.size();
	if (row == 0)
		return 0;

	int col = grid[0].size();
	if (col == 0)
		return 0;

	//make a new matrix, record which points has been visited
	marked.resize(row);
	for (int i = 0; i < row; i++)
		marked[i].resize(col);

	// initial this matrix as all false(all are unvisited)
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			marked[i][j] = false;
		}
	}

	int count = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			// if grid[i][j] == '1' and also it has not been unvisited,
			// then we found a new connected component (an island)
			if (marked[i][j] == false && grid[i][j] == '1')
			{
				count++;
				dfs(grid, marked, row, col, i, j);
			}
		}
	}
	return count;
}
vector<vector<char>> initGrid(vector<string> &vec)
{
	vector<vector<char>> grid;
	grid.resize(vec.size());
	for (int i = 0; i < vec.size(); i++)
	{
		grid[i].resize(vec[0].size());
	}

	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec[0].size(); j++)
		{
			grid[i][j] = vec[i][j];
		}
	}
	return grid;
}

template <class T>
void show(vector <vector <T>> &data)
{
	for (int i = 0; i < data.size(); i++)
	{
		for (int j = 0; j < data[0].size(); j++)
		{
			cout << data[i][j] << " ";
		}
		cout << endl;
	}
}