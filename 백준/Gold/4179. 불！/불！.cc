#include<iostream>
#include<queue>
using namespace std;

void BFS(queue<pair<int, int>> q_Ji, queue<pair<int, int>> q_Fire);

string strBoard[1002];
int iDist[1002][1002];
int iDistFire[1002][1002];

int dx[4]{ 1, 0, -1, 0 };
int dy[4]{ 0, 1, 0 ,-1 };

int n(0), m(0);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	queue<pair<int, int>> q_Ji;
	queue<pair<int, int>> q_Fire;

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		fill(iDist[i], iDist[i] + m, -1);
		fill(iDistFire[i], iDistFire[i] + m, -1);
	}

	for (int i = 0; i < n; ++i)
	{
		cin >> strBoard[i];

		for (int j = 0; j < m; ++j)
		{
			if (strBoard[i][j] == 'J')
			{
				q_Ji.push({ i,j });	// 지훈의 시작점을 저장
				iDist[i][j] = 0;
			}

			if (strBoard[i][j] == 'F')
			{
				q_Fire.push({ i,j });	// 불의 시작점을 저장
				iDistFire[i][j] = 0;
			}
		}
	}

	BFS(q_Ji, q_Fire);

	return 0;
}

void BFS(queue<pair<int, int>> q_Ji, queue<pair<int, int>> q_Fire)
{
	// 불 BFS
	while (!q_Fire.empty())
	{
		pair<int, int> FTemp = q_Fire.front();
		q_Fire.pop();
		for (int i = 0; i < 4; ++i)
		{
			int mx = FTemp.first + dx[i];
			int my = FTemp.second + dy[i];

			if (mx < 0 || mx >= n || my < 0 || my >= m)
				continue;

			if (iDistFire[mx][my] >= 0 || strBoard[mx][my] == '#')
				continue;

			iDistFire[mx][my] = iDistFire[FTemp.first][FTemp.second] + 1;
			q_Fire.push({ mx, my });
		}
	}

	// 지훈 BFS
	while (!q_Ji.empty())
	{
		pair<int, int> temp = q_Ji.front();
		q_Ji.pop();

		for (int i = 0; i < 4; ++i)
		{
			int mx = temp.first + dx[i];
			int my = temp.second + dy[i];

			if (mx < 0 || mx >= n || my < 0 || my >= m)
			{
				// 탈출 성공
				int result = iDist[temp.first][temp.second];
				cout << result + 1;
				return;
			}

			if (iDist[mx][my] >= 0 ||  strBoard[mx][my] == '#')
				continue;

			if (iDistFire[mx][my] != -1 && iDistFire[mx][my] <= iDist[temp.first][temp.second] + 1)
				continue;

			iDist[mx][my] = iDist[temp.first][temp.second] + 1;
			q_Ji.push({ mx, my });
		}
	}

	cout << "IMPOSSIBLE";
}