#include<iostream>
#include<queue>
using namespace std;

void BFS(queue<pair<int, int>> q);

int iBoard[1001][1001];
int iDist[1001][1001];

int dx[4]{ 1, 0, -1, 0};
int dy[4]{ 0, 1, 0 ,-1};

int n(0), m(0);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	queue<pair<int, int>> q;

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> iBoard[i][j];
			iDist[i][j] = -1;

			if (iBoard[i][j] == 2)
			{
				q.push({ i,j });
				iDist[i][j] = 0;
			}
		}
	}
	
	BFS(q);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (iBoard[i][j] == 1 && iDist[i][j] == -1) // 갈 수 있는 지역이지만 도달 불가
				iDist[i][j] = -1;
			else if (iBoard[i][j] == 0 && iDist[i][j] == -1)
				iDist[i][j] = 0;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << iDist[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}

void BFS(queue<pair<int, int>> q)
{
	while (!q.empty())
	{
		pair<int, int> iTemp = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int mx = iTemp.first + dx[i];
			int my = iTemp.second + dy[i];

			if (mx < 0 || mx >= n || my < 0 || my >= m)
				continue;

			if (iBoard[mx][my] == 0)
			{
				iDist[mx][my] = 0;
				continue;
			}

			if (iDist[mx][my] != -1)
				continue;

			q.push({ mx,my });
			iDist[mx][my] = iDist[iTemp.first][iTemp.second] + 1;
		}
	}
}