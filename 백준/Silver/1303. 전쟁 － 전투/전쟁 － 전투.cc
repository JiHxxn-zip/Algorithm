using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

string board[101];
bool vis[101][101];

int n, m;

int dx[4]{0, 0, -1, 1};
int dy[4]{1, -1, 0, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> board[i];
    }

    vector<int> vec_w;  // 하얀색
    vector<int> vec_b;  // 파란색

    // 전수 검사
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // 방문 예외처리
            if (vis[i][j])
                continue;

            queue<pair<int,int>> q;
            q.push({i, j});

            vis[i][j] = true;

            // 여기서 현재 char가 w인지 b인지 확인
            char curColor = board[i][j];
            int colorCount{};

            while (!q.empty())
            {
                auto cur = q.front();
                q.pop();

                ++colorCount;

                for (int k = 0; k < 4; k++)
                {
                    int nx = dx[k] + cur.second;
                    int ny = dy[k] + cur.first;

                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue;

                    if (vis[ny][nx])
                        continue;

                    if (board[ny][nx] == curColor)
                    {
                        vis[ny][nx] = true;
                        q.push({ny, nx});
                    }
                }
            }

            if (curColor == 'W')
                vec_w.push_back(colorCount*colorCount);
            else if (curColor == 'B')
                vec_b.push_back(colorCount * colorCount);
        }
    }

    int sumW{}, sumB{};
    for (int i = 0; i < vec_w.size(); i++)
        sumW += vec_w[i];

    for (int i = 0; i < vec_b.size(); i++)
        sumB += vec_b[i];

    cout << sumW << ' ' << sumB;

    return 0;
}

// BFS 문제