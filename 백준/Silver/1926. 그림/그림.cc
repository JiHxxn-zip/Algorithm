#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "algorithm"
using namespace std;

int board[501][501];
int vis[501][501];

int dx[4]{ 0, 0, -1, 1 };
int dy[4]{ 1, -1, 0, 0 };


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 행과 열을 저장해줄 변수
    int row, col;

    cin >> row >> col;

    // Board 셋팅
    for (size_t i = 0; i < row; i++)
        for (size_t j = 0; j < col; j++)
            cin >> board[i][j];

    // 그림의 수
    int count{};

    // 찾은 그림들 중 가장 큰 영역의 수
    int mx{};

    // 전수 검사를 위해 2중 포문안에 BFS를 넣어주어야함
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            if (vis[i][j] == 1 || board[i][j] == 0)
                continue;

            // 갈 수 있는 위치를 저장해주는 q
            queue<pair<int, int>> q;
            q.push({ i, j });

            // 방문
            vis[i][j] = 1;

            // 새로운 BFS가 시작되는 시점이 새로운 영역(그림)이라는 뜻
            ++count;

            // 그림마다 영역을 체크해줄 일회성 변수
            int area{};

            // BFS 시작
            while (!q.empty())
            {
                ++area;

                pair<int, int> cur = q.front();
                q.pop();

                for (size_t i = 0; i < 4; i++)
                {
                    int nx = cur.second + dx[i];
                    int ny = cur.first + dy[i];

                    if (nx < 0 || nx >= col || ny < 0 || ny >= row)
                        continue;
                    if (vis[ny][nx] == 1 || board[ny][nx] == 0)
                        continue;

                    vis[ny][nx] = 1;
                    q.push({ ny, nx });
                }
            }
            
            // 가장 큰 영역 교체
            mx = max(mx, area);
        }
    }

    cout << count << "\n" << mx;

    return 0;
}       

// 그림의 수와 그림들 중 가장 큰 영역의 수 출력하기 ->줄바꿈
// BFS 전수검사 문제
// 그림의 수를 세어줄 변수와 영역크기를 세어줄 변수가 필요함
// 행 열 순으로 받고, int 2차원 배열로 받는다
// vis가 필요한 문제
