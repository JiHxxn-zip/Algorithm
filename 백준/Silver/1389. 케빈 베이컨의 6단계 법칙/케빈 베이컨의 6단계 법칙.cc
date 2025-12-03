#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <climits> // INT_MAX

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int answer{};
    int minSum = INT_MAX;

    for (int i = 1; i <= n; i++)
    {
        vector<int> dist(n + 1, -1);
        queue<int> q;

        dist[i] = 0;
        q.push(i);

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            for (int nxt : adj[cur])
            {
                if (dist[nxt] == -1)
                {
                    dist[nxt] = dist[cur] + 1;
                    q.push(nxt);
                }
            }
        }

        int sum = 0;
        for (int j = 1; j <= n; j++)
            sum += dist[j];

        if (sum < minSum)
        {
            minSum = sum;
            answer = i;
        }
    }

    cout << answer << '\n';
    return 0;
}
