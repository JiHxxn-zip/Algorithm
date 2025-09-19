#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "algorithm"
using namespace std;



int dx[4]{ 0,0,-1,1 };
int dy[4]{ 1,-1,0,0 };

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int testCase{};
    cin >> testCase;

    for (size_t i = 0; i < testCase; i++)
    {
        int col, row, num;
        cin >> col >> row >> num;

        int board[51][51];
        int vis[51][51];
        for (size_t i = 0; i < 51; i++)
        {
            for (size_t j = 0; j < 51; j++)
            {
                board[i][j] = 0;
                vis[i][j] = 0;
            }
        }

        for (size_t i = 0; i < num; i++)
        {
            int posX, posY;
            cin >> posX >> posY;

            board[posY][posX] = 1;
        }

        int count{};

        // 전수 검사
        for (size_t i = 0; i < row; i++)
        {
            for (size_t j = 0; j < col; j++)
            {
                if (vis[i][j] > 0 || board[i][j] != 1)
                    continue;

                count++;

                // BFS 시작
                queue<pair<int, int>> q;
                q.push({ i, j });

                vis[i][j] = 1;

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
                        if (vis[ny][nx] > 0 || board[ny][nx] != 1)
                            continue;

                        vis[ny][nx] = 1;
                        q.push({ ny, nx });
                    }
                }

            }
        }

        cout << count << '\n';
    }
    
    return 0;
}       
