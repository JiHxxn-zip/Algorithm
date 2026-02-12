using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <limits>
#include <cctype> 
#include <iomanip>
#include <queue>

typedef long long ll;

string board[2001];
char vis[2001][2001];

int dx[7]{ 0, -1, 1, -1, -1, 1, 1 };// 상,하,좌,우, 왼위, 왼아, 오위, 오아
int dy[7]{ -1, 0, 0, 1, -1, 1, -1 };// 상,하,좌,우, 왼위, 왼아, 오위, 오아

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
   
    pair<int, int> start{};
    for (int i = 0; i < n; i++)
    {
        cin >> board[i];

        for (int j = 0; j < board[i].size(); j++)
            if (board[i][j] == 'F')
                start = {i, j};
    }

    queue<pair<int, int>> q;
    q.push(start);
    vis[start.first][start.second] = 1;

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
            if (vis[ny][nx] || board[ny][nx] != '.')
                continue;

            vis[ny][nx] = 1;
            q.push({ny, nx});
            answer++;
        }
    }

    cout << answer;

   
    return 0;
}