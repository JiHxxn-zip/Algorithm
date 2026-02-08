using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <climits> // INT_MAX

typedef long long ll;

string board[2001];

bool vis[2001][2001];
int dx[7]{ 0,-1,1, -1,1,-1,1 }; // 하좌우 위왼 위오 아왼 아오
int dy[7]{ -1,0,0,  1,1,-1,-1 };


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> board[i];


	// . 이동가능 # 벽 F 도착지점
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < board[i].size(); j++)
			if (board[i][j] == 'F')
			{
				q.push({ i,j });
				vis[i][j] = true;
			}
	
	int answer{};

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 7; i++)
		{
			int nx = dx[i] + cur.second;
			int ny = dy[i] + cur.first;

			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;
			if (board[ny][nx] == '#')
				continue;
			if (vis[ny][nx]) 
				continue;

			vis[ny][nx] = true;
			q.push({ ny, nx });

			if (board[ny][nx] == '.')
				answer++;
		}
	}

	cout << answer;

	return 0;
}