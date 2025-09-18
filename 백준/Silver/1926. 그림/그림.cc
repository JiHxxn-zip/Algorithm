#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "algorithm"
using namespace std;

int board[502][502];
int vis[502][502];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

int row{}, col{};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> row >> col;

    for (size_t i = 0; i < row; i++)
        for (size_t j = 0; j < col; j++)
            cin >> board[i][j];

    int mx{};   // 그림의 최대 범위 
    int num{};  // 그림의 수

    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            if (board[i][j] == 0 || vis[i][j] == true)
                continue;

            // 그림의 수를 체크
            ++num;

            queue<pair<int, int>> q;
            q.push({ i,j });

            // 방문 체크
            vis[i][j] = 1;

            int area{};
            
            while (!q.empty())
            {
                // 그림 하나의 크기를 세어준다.
                ++area;

                auto cur = q.front();
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

            // 각 그림마다 영억의 크기중 가장 큰 그림을 저장
            mx = max(mx, area);
        }
    }

    cout << num << '\n' << mx;

    return 0;
}       
