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

    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (deg[i] == 0)
            q.push(i);
    
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';

        for (auto a : vec[cur])
        {
            deg[a]--;
            if (deg[a] == 0)
                q.push(a);
        }
    }
    
    return 0;
}

// 방향 그래프
// degree 저장
// 0이 될 때 가지 돌리고, 0 이면 answer vector에 저장