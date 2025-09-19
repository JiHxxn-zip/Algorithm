#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "algorithm"
using namespace std;

string board[1001];
int f_Dist[1001][1001]; // 불 dist
int j_Dist[1001][1001]; // 지훈 disg

int dx[4]{ 0, 0, -1, 1 };
int dy[4]{ 1, -1, 0, 0 };

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 행과 열을 저장해줄 변수
    int row, col;

    cin >> row >> col;

    // 갈 수 없는 지역 셋팅
    for (size_t i = 0; i < row; i++)
    {
        fill(f_Dist[i], f_Dist[i] + col, -1);
        fill(j_Dist[i], j_Dist[i] + col, -1);
    }

    // Board 셋팅
    for (size_t i = 0; i < row; i++)
        cin >> board[i];

    // 갈 수 있는 위치를 저장해주는 q
    queue<pair<int, int>> q;
    for (size_t i = 0; i < row; i++)
        for (size_t j = 0; j < col; j++)
            if (board[i][j] == 'F')
            {
                q.push({ i, j });
                f_Dist[i][j] = 0;
            }
    
    // 불 BFS 시작
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        for (size_t i = 0; i < 4; i++)
        {
            int nx = cur.second + dx[i];
            int ny = cur.first + dy[i];

            if (nx < 0 || nx >= col || ny < 0 || ny >= row)
                continue;
            if (f_Dist[ny][nx] >= 0 || board[ny][nx] == '#')
                continue;

            f_Dist[ny][nx] = f_Dist[cur.first][cur.second] + 1;
            q.push({ ny, nx });
        }
    }

    for (size_t i = 0; i < row; i++)
        for (size_t j = 0; j < col; j++)
            if (board[i][j] == 'J')
            {
                q.push({ i, j });
                j_Dist[i][j] = 0;
            }

    // 탈출 위치 저장
    pair<int, int> exit;

    // 지훈 BFS 시작
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
    
        for (size_t i = 0; i < 4; i++)
        {
            int nx = cur.second + dx[i];
            int ny = cur.first + dy[i];

            if (nx < 0 || nx >= col || ny < 0 || ny >= row)
            {
                cout << j_Dist[cur.first][cur.second] + 1;
                return 0;
            }
    
            if (j_Dist[ny][nx] >= 0 || board[ny][nx] == '#')
                continue;
            int nextTime = j_Dist[cur.first][cur.second] + 1;

            // 지훈이가 가려는 위치에 불이 존재하고, 불이 먼저왔다면(숫자가 작다면)
            if (f_Dist[ny][nx] != -1 && f_Dist[ny][nx] <= nextTime)
                continue;

            j_Dist[ny][nx] = j_Dist[cur.first][cur.second] + 1;
            q.push({ ny, nx });
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}       

// 거리 측정이 필요한 BFS 문제
// 예외처리가 좀 다르게 가장자리로 가야 탈출.
// 벽이 있는 곳은 갈 수 없음
// 사이즈는 1000
// 벽은 #, J는 초기 위치, F는 불, .은 이동 가능위치
// 행, 열, string board

// 서로 상호 작용하는 조건은 없기 때문에 불의 dist와 지훈의 dist를 구해서 비교
// 지훈이를 결국 탈출 시켜야하기 때문에 불의 dist를 먼저 다 구하고 
// 지훈이의 BFS에서 불의 dist를 가지고 놀면 될듯