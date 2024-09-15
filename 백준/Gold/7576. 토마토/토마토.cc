#include<iostream>
#include<queue>
using namespace std;

string strBoard[102];
int iBoard[1002][1002];
int iDist[1002][1002];

int dx[4]{ 1, 0, -1, 0 };
int dy[4]{ 0, 1, 0 ,-1 };

int n(0), m(0);


void BFS(queue<pair<int, int>> q);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	queue<pair<int, int>> q;

	cin >> m >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> iBoard[i][j];

			if (iBoard[i][j] == 1)
				q.push({ i,j });	// 시작점을 저장

			if (iBoard[i][j] == 0)	// 갈 수 있는 위치면
				iDist[i][j] = -1;	// dist엔 -1로 저장
		}
	}

	BFS(q);

	return 0;
}

void BFS(queue<pair<int, int>> q)
{
	while (!q.empty())
	{
		pair<int, int> temp = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int mx = temp.first + dx[i];
			int my = temp.second + dy[i];

			if (mx < 0 || mx >= n || my < 0 || my >= m)
				continue;
			
			if(0 <= iDist[mx][my])
				continue;

			iDist[mx][my] = iDist[temp.first][temp.second] + 1;
			q.push({ mx, my });
		}
	}

	int iAnswer(0);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (iDist[i][j] == -1)
			{
				cout << "-1";
				return;
			}

			iAnswer = max(iAnswer, iDist[i][j]);
		}
	}

	cout << iAnswer;
}