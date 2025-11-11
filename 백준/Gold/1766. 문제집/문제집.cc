using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

vector<int> vec[32001];
int deg[32001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    while (m--)
    {
        int a, b;
        cin >> a >> b;

        vec[a].push_back(b);
        deg[b]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq{};

    for (int i = 1; i <= n; i++)
    {
        if (deg[i] == 0)
            pq.push(i);
    }

    while (!pq.empty())
    {
        int cur = pq.top();
        pq.pop();

        cout << cur << ' ';

        for (auto a : vec[cur])
        {
            deg[a]--;
            if (deg[a] == 0)
                pq.push(a);
        }
    }

    return 0;
}