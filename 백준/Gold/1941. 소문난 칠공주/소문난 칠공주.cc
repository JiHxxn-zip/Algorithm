#include <iostream>
#include <vector>
#include <queue>
#include "algorithm"
using namespace std;

string board[5];
bool dfs_Vis[5][5];
int answer;

int dx[4]{ 0,0,-1,1 };
int dy[4]{ 1,-1,0,0 };
bool bfs_Vis[5][5];

bool BFS(int cur_I, int cur_J)
{
    for (size_t i = 0; i < 5; i++)
        fill(begin(bfs_Vis[i]), end(bfs_Vis[i]), false);

    queue<pair<int, int>> q;
    q.push({ cur_I, cur_J });
    bfs_Vis[cur_I][cur_J] = true;

    int count{ 1 };

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        if (count == 7)
            return true;

        for (size_t i = 0; i < 4; i++)
        {
            int nx = cur.second + dx[i];
            int ny = cur.first + dy[i];

            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
                continue;
            if (bfs_Vis[ny][nx])  // 이미 방문한 곳은 다시 방문하지 않음
                continue;
            if (!dfs_Vis[ny][nx])  // DFS에서 선택한 곳만 탐색
                continue;

            q.push({ ny, nx });
            bfs_Vis[ny][nx] = true;
            //넣을때 cnt ++;
            count++;

        }
    }

    return false;
}

// 현재 인덱스와, 사용된 숫자
void DFS(int cur_I, int cur_J, int total_Count, int s_Count)
{
    // 7명이 모였다면
    if (7 == total_Count)
    {
        // 시작점 아무거나 찾기 cur_I / cur_J가 다음 걸 기준으로 삼아서
        if (s_Count >= 4)
        {
            for (int r = 0; r < 5; ++r)
            {
                for (int c = 0; c < 5; ++c)
                {
                    if (dfs_Vis[r][c]) {
                        answer += BFS(r, c);
                        return;
                    }
                }
            }
        }
        return;
    }

    // 본문 시작
    for (int i = cur_I; i < 5; ++i) {
        int startJ;
        if (i == cur_I) 
            startJ = cur_J;
        else 
            startJ = 0;

        for (int j = startJ; j < 5; ++j) {
            if (dfs_Vis[i][j]) continue;

            dfs_Vis[i][j] = true;
            DFS(i, j + 1, total_Count + 1, s_Count + (board[i][j] == 'S'));
            dfs_Vis[i][j] = false;
        }
    }

    return;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Board 셋팅
    for (size_t i = 0; i < 5; i++)
        cin >> board[i];

    DFS(0, 0, 0, 0);

    cout << answer;

    return 0;
}

// 일단 1차원 배열로 안하고 2차원으로 시도해보기
// DFS 예외처리로 count가 7이 되었고, S가 4이상이라면 BFS를 돌린다
    // 반환 값으로 true가 나오면 result ++
// DFS 본문에서는 단순히 방문체크해주고 인자로 (카운트 +1, 깊이, s의 갯수)

// 현재 위치(curIndex)를 2차원으로 바꿔서 넘겨줄 경우
    // 인자로 i,j를 넘겨주면 안됨?