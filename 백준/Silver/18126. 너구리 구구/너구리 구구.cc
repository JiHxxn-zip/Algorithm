using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <limits>
#include <cctype> 
#include <iomanip>

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<vector<pair<int, int>>> graph(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c });
    }

    vector<bool> visited(n + 1, false);
    vector<ll> dist(n + 1, 0);

    queue<int> q;
    q.push(1);
    visited[1] = true;

    ll maxDist = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (auto& next : graph[cur])
        {
            int nextNode = next.first;
            int weight = next.second;

            if (!visited[nextNode])
            {
                visited[nextNode] = true;
                dist[nextNode] = dist[cur] + weight;
                q.push(nextNode);

                maxDist = max(maxDist, dist[nextNode]);
            }
        }
    }

    cout << maxDist;

    return 0;
}
