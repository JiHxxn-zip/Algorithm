using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <limits> // INT_MAX
#include <iomanip> // 소숫점 제한
#include <cstring> // memset

using ll = long long;

int n, m;
vector<vector<int>> vec;
int memo[1001][1001][4];

int DP(int row, int col, int prevDir)
{
	if (col < 0 || col >= m)
		return numeric_limits<int>::max();

	if (row == n - 1)
		return vec[row][col];

	int& ret = memo[row][col][prevDir];
	if (ret != -1)
		return ret;

	ret = numeric_limits<int>::max();

	// 0 = 왼쪽, 1 = 중앙, 2 = 오른쪽
	if (prevDir != 0)
		ret = min(ret, DP(row + 1, col - 1, 0));

	if (prevDir != 1)
		ret = min(ret, DP(row + 1, col, 1));

	if (prevDir != 2)
		ret = min(ret, DP(row + 1, col + 1, 2));

	return ret += vec[row][col];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	vec.assign(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> vec[i][j];

	memset(memo, -1, sizeof(memo));

	int minAnswer = numeric_limits<int>::max();
	for (int i = 0; i < m; i++)
		minAnswer = min(minAnswer, DP(0, i, 3));
	
	cout << minAnswer;

	return 0;
}