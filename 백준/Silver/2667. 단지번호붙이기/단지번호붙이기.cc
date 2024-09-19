#include<iostream>
#include<queue>
#include <vector>
#include <algorithm>
using namespace std;

void BFS(queue<pair<int, int>> q);

string strBoard[27];
bool bVis[27][27];
vector<int> vecAPTCount;

int dx[4]{ 1, 0, -1, 0 };
int dy[4]{ 0, 1, 0 ,-1 };

int n(0);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	queue<pair<int, int>> q;
	int iNum(0);

	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> strBoard[i];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (strBoard[i][j] == '0' || bVis[i][j])
				continue;

			++iNum; // 단지 수

			q.push({i,j});
			bVis[i][j] = true;

			BFS(q);
			q.pop();
		}
	}

	sort(vecAPTCount.begin(), vecAPTCount.end());

	cout << iNum << '\n';
	for (int i = 0; i < vecAPTCount.size(); i++)
		cout << vecAPTCount[i] << '\n';

	return 0;
}

void BFS(queue<pair<int, int>> q)
{
	int iArea(0); // 단지 내 집의 수

	while (!q.empty())
	{
		++iArea;

		pair<int, int> iTemp = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int mx = iTemp.first + dx[i];
			int my = iTemp.second + dy[i];

			if (mx < 0 || mx >= n || my < 0 || my >= n)
				continue;

			if (bVis[mx][my] || strBoard[mx][my] != '1')
				continue;

			q.push({ mx,my });
			bVis[mx][my] = true;
		}
	}

	vecAPTCount.push_back(iArea);
}