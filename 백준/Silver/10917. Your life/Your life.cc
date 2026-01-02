using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <climits>
#include <cctype> 


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> vec(n + 1);
    vector<int> dist(n + 1, -1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    queue<int> q;
    q.push(1);

    dist[1] = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (auto next : vec[cur])
        {
            if (dist[next] != -1)
                continue;

            q.push(next);
            dist[next] = dist[cur] + 1;
        }
    }

    cout << dist[n];

    return 0;
}

