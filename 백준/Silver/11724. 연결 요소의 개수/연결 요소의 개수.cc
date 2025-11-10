using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> vec[1001];
    vector<int> vis(1001);
    fill(vis.begin(), vis.end(), false);

    while (m--)
    {
        int u, v;
        cin >> u >> v;

        vec[u].push_back(v);
        vec[v].push_back(u);
    }

    // BFS
    int count{};
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;

        count++;
        queue<int> q;
        q.push(i);
        vis[i] = true;

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            // 현재 정점의 연결된 정점 전수 검사
            for (auto next : vec[cur])
            {
                if (vis[next])
                    continue;

                q.push(next);
                vis[next] = true;
            }
        }
    }

    cout << count;

    return 0;
}

// 그래프 BFS
// 요소의 갯수, 요소 == 연결된 정점들의 집합의 갯수