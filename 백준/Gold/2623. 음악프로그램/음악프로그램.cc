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
    int deg[1001]{ 0 };

    while (m--)
    {
        int num;
        cin >> num;

        vector<int> oder(num);

        for (int i = 0; i < num; i++)
            cin >> oder[i];

        for (int i = 0; i < num - 1; i++)
        {
            int a = oder[i];
            int b = oder[i + 1];

            vec[a].push_back(b);
            deg[b]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (deg[i] == 0)
            q.push(i);
    
    vector<int> result;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        result.push_back(cur);

        for (auto a : vec[cur])
        {
            deg[a]--;
            if (deg[a] == 0)
                q.push(a);
        }
    }

    if (result.size() == n)
        for (auto a : result)
            cout << a << '\n';
    else
        cout << 0;

    return 0;
}

// 방향 그래프
// degree 저장
// 0이 될 때 가지 돌리고, 0 이면 answer vector에 저장