#include<iostream>
#include<queue>
using namespace std;

string strBoard[102];
int iDist[102][102];

int dx[4]{ 1, 0, -1, 0 };
int dy[4]{ 0, 1, 0 ,-1 };

int n(0), m(0);

void BFS();

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> strBoard[i];

	for (int i = 0; i < n; ++i)
		fill(iDist[i], iDist[i] + m, -1);

	BFS();

	return 0;
}

void BFS()
{
	queue<pair<int, int>> q;
	q.push({0, 0});

	iDist[0][0] = 0;

	while (!q.empty())
	{
		pair<int, int> temp = q.front();
		q.pop();

		for (int k = 0; k < 4; ++k)
		{
			int mx = temp.first + dx[k];
			int my = temp.second + dy[k];

			if (mx < 0 || mx > n || my < 0 || my > m)
				continue;

			if (iDist[mx][my] >= 0 || strBoard[mx][my] != '1')
				continue;

			iDist[mx][my] = iDist[temp.first][temp.second] + 1;
			q.push({ mx, my });
		}
	}

	cout << iDist[n-1][m-1] + 1;
}