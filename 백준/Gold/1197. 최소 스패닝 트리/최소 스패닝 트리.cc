using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

struct Edge
{
    int u, v;
    int w;
};

int parent[100001];

int findParent(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = findParent(parent[x]);
}

bool unite(int a, int b)
{
    a = findParent(a);
    b = findParent(b);
    if (a == b)
        return false;

    parent[b] = a;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int v, e;
    cin >> v >> e;

    vector<Edge> edges;
    edges.reserve(e);

    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        edges.push_back({a, b, c});
    }

    sort(edges.begin(), edges.end(),
        [](Edge& a, Edge& b)
        {
            return a.w < b.w;
        });

    for (int i = 1; i <= v; i++)
        parent[i] = i;

    long long answer = 0;

    for (auto e : edges)
        if (unite(e.u, e.v))
            answer += e.w;

    cout << answer << '\n';
    return 0;
}

// 최소 신장 트리
