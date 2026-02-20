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

    vector<vector<pair<int, int>>> vec(n+1);

    for (int i = 0; i < n-1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        vec[a].push_back({ b,c });
        vec[b].push_back({ a,c });
    }

    queue<int> q;
    q.push(1);

    vector<bool> vis(n+1, false);
    vis[1] = true;

    vector<ll> dist(n + 1, 0);

    ll answer{};

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (auto& next : vec[cur])
        {
            int nx = next.first;
            int w = next.second;

            if (vis[nx])
                continue;

            q.push(nx);
            dist[nx] = dist[cur] + w;
            vis[nx] = true;

            answer = max(answer, dist[nx]);
        }
    }

    cout << answer;

    return 0;
}