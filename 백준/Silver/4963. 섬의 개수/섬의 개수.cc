#include<iostream>
#include<queue>
using namespace std;

void BFS(queue<pair<int, int>> q);

int iBoard[51][51];
bool bVis[51][51];

int dx[8]{ 1, 0, -1, 0, -1, 1, -1, 1};
int dy[8]{ 0, 1, 0 ,-1, 1, 1, -1, -1};

int iNum(0);
int h(0), w(0);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	queue<pair<int, int>> q;

	while (true)
	{
		cin >> w >> h;

		if (0 == h || 0 == w)
			break;

		for (int i = 0; i < 51; ++i)
		{
			for (int j = 0; j < 51; ++j)
			{
				iBoard[i][j] = -1;
				bVis[i][j] = false;
			}
		}

		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				cin >> iBoard[i][j];
			}
		}

		iNum = 0;
		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				if (iBoard[i][j] == -1 || bVis[i][j] || iBoard[i][j] == 0)
					continue;

				q.push({ i,j });
				bVis[i][j] = true;

				BFS(q);

				q.pop();
			}
		}

		// 섬의 갯수 출력
		cout << iNum << '\n';
	}

	return 0;
}

void BFS(queue<pair<int, int>> q)
{
	++iNum;

	while (!q.empty())
	{
		pair<int, int> iTemp = q.front();
		q.pop();
		for (int i = 0; i < 8; ++i)
		{
			int mx = iTemp.first + dx[i];
			int my = iTemp.second + dy[i];

			if (mx < 0 || mx >= h || my < 0 || my >= w)
				continue;

			if (bVis[mx][my] || iBoard[mx][my] == -1 || iBoard[mx][my] == 0)
				continue;

			q.push({ mx,my });
			bVis[mx][my] = true;
		}
	}
}