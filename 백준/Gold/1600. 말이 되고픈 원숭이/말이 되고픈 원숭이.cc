using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits>
#include <cctype> 
#include <iomanip>

typedef long long ll;

struct Used
{
    Used(int _y, int _x, int _used) : y(_y), x(_x), used(_used) {};
    int y, x, used;
};

int dy4[] = { -1, 1, 0, 0 };
int dx4[] = { 0, 0, -1, 1 };

int dy8[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dx8[] = { -1, 1, -2, 2, -2, 2, -1, 1 };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k;
    cin >> k;

    int w, h;
    cin >> w >> h;

    vector<vector<int>> board(h, vector<int>(w));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> board[i][j];

    vector<vector<vector<int>>> dist(h, vector<vector<int>>(w, vector<int>(k + 1, -1)));
    queue<Used> q;
    q.push(Used(0, 0, 0));
    dist[0][0][0] = 0;

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        if (h - 1 == cur.y && w - 1 == cur.x)
        {
            cout << dist[cur.y][cur.x][cur.used];
            return 0;
        }

        for (int i = 0; i < 4; i++)
        {
            int ny = cur.y + dy4[i];
            int nx = cur.x + dx4[i];
            
            if (ny < 0 || ny >= h || nx < 0 || nx >= w)
                continue;
            if (board[ny][nx] == 1)
                continue;
            if (dist[ny][nx][cur.used] != -1)
                continue;

            dist[ny][nx][cur.used] = dist[cur.y][cur.x][cur.used] + 1;
            q.push(Used(ny,nx,cur.used));
        }

        if (cur.used < k)
        {
            for (int i = 0; i < 8; i++)
            {
                int ny = cur.y + dy8[i];
                int nx = cur.x + dx8[i]; 
                int nextUsed = cur.used + 1;

                if (ny < 0 || ny >= h || nx < 0 || nx >= w)
                    continue;
                if (board[ny][nx] == 1)
                    continue;
                if (dist[ny][nx][nextUsed] != -1)
                    continue;

                dist[ny][nx][nextUsed] = dist[cur.y][cur.x][cur.used] + 1;
                q.push(Used(ny, nx, nextUsed));
            }
        }

    }
    cout << "-1";

    return 0;
}