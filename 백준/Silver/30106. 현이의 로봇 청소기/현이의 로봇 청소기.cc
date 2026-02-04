using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cctype> 
#include <iomanip>
#include <unordered_map>
#include <queue>

typedef long long ll;

int board[501][501];
bool vis[501][501];

int dx[4]{ 0,0,-1,1 };
int dy[4]{ 1, -1, 0, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    }

    int answer{};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j])
                continue;

            answer++;

            queue<pair<int,int>> q;
            q.push({i,j});

            while (!q.empty())
            {
                auto cur = q.front();
                q.pop();

                for (int d = 0; d < 4; d++)
                {
                    int nx = dx[d] + cur.second;
                    int ny = dy[d] + cur.first;

                    if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                        continue;
                    if (vis[ny][nx])
                        continue;
                    if (k < abs(board[cur.first][cur.second] - board[ny][nx]))
                        continue;

                    q.push({ ny, nx });
                    vis[ny][nx] = true;
                }
            }
        }
    }

    cout << answer;
    return 0;
}
