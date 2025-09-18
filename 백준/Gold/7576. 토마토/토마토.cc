#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "algorithm"
using namespace std;

int board[1002][1002];
int dist[1002][1002];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

int row{}, col{};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> col >> row;

    queue<pair<int, int>> q;
 
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cin >> board[i][j];

            // 만약 board 전수 검사 시 1이 나오면 Start Pos임
            if (board[i][j] == 1)
                q.push({ i,j });

            // 갈 수 있는 지역을 -1로 
            if (board[i][j] == 0)
                dist[i][j] = -1;
        }
    }

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for (size_t i = 0; i < 4; i++)
        {
            int nx = cur.second + dx[i];
            int ny = cur.first + dy[i];

            if (nx < 0 || nx >= col || ny < 0 || ny >= row)
                continue;
            if (dist[ny][nx] >= 0)
                continue;

            // 핵심
            dist[ny][nx] = dist[cur.first][cur.second] + 1; 
            q.push({ ny, nx });
        }
    }

    int answer{};

    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            if (dist[i][j] == -1)
            {
                cout << "-1";
                return 0;
            }

            // 가장 큰 값 저장
            answer = max(answer, dist[i][j]);
        }
    }

    cout << answer;

    return 0;
}       
