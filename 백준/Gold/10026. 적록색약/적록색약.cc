#include<iostream>
#include<queue>
using namespace std;

void BFS(queue<pair<int, int>> q);
void BFS2(queue<pair<int, int>> q);

string strBoard[101];
bool bVis[101][101];
bool bVis2[101][101];

int dx[4]{ 1, 0, -1, 0 };
int dy[4]{ 0, 1, 0 ,-1 };

int n(0);
char curr('\0');

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	queue<pair<int, int>> q;
	int iNum(0), iNum2(0);

	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> strBoard[i];

	curr = '\0';

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (bVis[i][j] || curr)
				continue;

			curr = strBoard[i][j];

			++iNum; // 단지 수

			q.push({i,j});
			bVis[i][j] = true;

			BFS(q);
			q.pop();
			curr = '\0';
		}
	}

	for (int i = 0; i < n; ++i)
	{
		curr = '\0';
		for (int j = 0; j < n; ++j) // RG 합쳐진 거 계산
		{
			if (bVis2[i][j])
				continue;

			if (curr == 'B')
				continue;

			if ((curr == 'R' && 'R' == strBoard[i][j]) || curr == 'G' && 'G' == strBoard[i][j])
				continue;

			curr = strBoard[i][j];

			++iNum2; // 단지 수

			q.push({ i,j });
			bVis2[i][j] = true;

			BFS2(q);
			q.pop();
			curr = '\0';
		}
	}

	cout << iNum << ' ' << iNum2;

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

			if (mx < 0 || mx >= n || my < 0 || my >= n)
				continue;

			if (bVis[mx][my] || strBoard[mx][my] != curr)
				continue;

			q.push({ mx,my });
			bVis[mx][my] = true;
		}
	}
}

void BFS2(queue<pair<int, int>> q)
{
	while (!q.empty())
	{
		pair<int, int> iTemp = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int mx = iTemp.first + dx[i];
			int my = iTemp.second + dy[i];

			if (mx < 0 || mx >= n || my < 0 || my >= n)
				continue;

			if (bVis2[mx][my])
				continue;

			// B일 경우에 R,G는 continue
			if(curr == 'B' && ('R' == strBoard[mx][my] || 'G' == strBoard[mx][my]))
				continue;

			// R,G일 경우 B일 경우 continue
			if ((curr == 'R' || curr == 'G') && 'B' == strBoard[mx][my])
				continue;

			q.push({ mx,my });
			bVis2[mx][my] = true;
		}
	}
}