#include<iostream>
#include<queue>
using namespace std;


int iBoard[502][502];
bool bVisit[502][502];

int dx[4]{ 1, 0, -1, 0 };
int dy[4]{ 0, 1, 0 ,-1 };

int n(0), m(0);
int iDraw(0), iMax(0);

void BFS();

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(false);
	
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			cin >> iBoard[i][j];
	}

	BFS();

	cout << iDraw << endl << iMax;
	return 0;
}

void BFS()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (iBoard[i][j] == 0 || bVisit[i][j])
				continue;

			++iDraw; // 지역에 첫 방문
			queue<pair<int, int>> q;
			q.push({ i,j });

			bVisit[i][j] = true;

			int iCount(0);
			while (!q.empty())
			{
				++iCount;

				pair<int, int> temp = q.front();
				q.pop();

				for (int k = 0; k < 4; ++k)
				{
					int mx = temp.first + dx[k];
					int my = temp.second + dy[k];

					if (mx < 0 || mx > n || my < 0 || my > m)
						continue;

					if (iBoard[mx][my] == 0 || bVisit[mx][my])
						continue;

					q.push({ mx, my });
					bVisit[mx][my] = true;
				}

			}

			iMax = iMax < iCount ? iCount : iMax;
		}
	}
}