using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits>
#include <cctype> 
#include <iomanip>

typedef long long ll;

struct WallData
{
    WallData(int _y, int _x, int _broken) : y(_y), x(_x), broken(_broken){}

    int y, x, broken;
};

int dx[4]{ 0,0,-1,1 };
int dy[4]{ 1,-1,0,0 };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> board(n);
    for (int i = 0; i < n; i++)
        cin >> board[i];

    // queue에 broken 원소까지
    queue<WallData> q;
    q.push(WallData(0,0,0));

    vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(2, 0)));
    dist[0][0][0] = 1;

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        if (cur.y == n - 1 && cur.x == m - 1)
        {
            cout << dist[cur.y][cur.x][cur.broken];
            return 0;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx >= m || nx < 0 || ny >= n || ny < 0)
                continue;

            if (board[ny][nx] == '0' && dist[ny][nx][cur.broken] == 0)
            {
                dist[ny][nx][cur.broken] = dist[cur.y][cur.x][cur.broken]+1;
                q.push(WallData(ny,nx,cur.broken));
            }

            if (board[ny][nx] == '1' && dist[ny][nx][1] == 0 && cur.broken == 0)
            {
                dist[ny][nx][1] = dist[cur.y][cur.x][cur.broken]+1;
                q.push(WallData(ny, nx, 1));
            }

        }
    }

    cout << "-1";

    return 0;
}
