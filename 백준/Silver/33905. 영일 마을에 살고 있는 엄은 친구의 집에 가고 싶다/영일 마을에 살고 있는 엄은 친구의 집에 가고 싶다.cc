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

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> vec(n+2);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    vector<int> leaveFriend(k);
    for (int i = 0; i < k; i++)
    {
        cin >> leaveFriend[i];
    }
    
    queue<int> q;
    q.push(1);

    vector<char> vis(n+2, 0);
    vis[1] = true;

    int count{};
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();


        bool c = { false };
        for (int j = 0; j < k; j++)
        {
            if (leaveFriend[j] == cur)
                c = true;
        }
        if (c)
            continue;

        if (cur != 1)
            count++;

        for (auto& x : vec[cur])
        {
            if (vis[x])
                continue;

            bool ch = { false };
            for (int j = 0; j < k; j++)
            {
                if (leaveFriend[j] == x)
                {
                    ch = true;
                    vis[x] = true;
                }
            }

            if (!ch)
            {
                vis[x] = true;
                q.push(x);
            }
        }

    }
    cout << count;
    
    return 0;
}
