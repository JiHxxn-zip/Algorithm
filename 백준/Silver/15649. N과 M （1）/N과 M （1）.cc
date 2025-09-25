#include <iostream>
using namespace std;

int n, m;
int answer[10];
int vis[10];

void DFS(int depth)
{
    // 현재 깊이와 m이 같다면 출력 후 리턴(더 이상 깊어 지지 않도록)
    if (depth == m)
    {
        for (int i = 0; i < m; ++i)
            cout << answer[i] << ' ';
        
        cout << '\n';
        return;
    }

    // 깊이 탐색(백트래킹)
    for (size_t i = 0; i < n; i++)
    {
        if (!vis[i]) 
        {
            answer[depth] = i + 1;
            vis[i] = true;
            DFS(depth + 1);
            vis[i] = false;

        }
    }
    return;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    DFS(0);

    return 0;
}