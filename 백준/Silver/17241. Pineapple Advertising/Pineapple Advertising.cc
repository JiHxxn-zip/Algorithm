using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <limits>
#include <iomanip> // 소숫점 제한


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // 집, 길, 피자
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> vec(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    vector<bool> vis(n + 1, false);
    vector<bool> firstVis(n + 1, false);

    for (int i = 0; i < q; i++)
    {
        int s;
        cin >> s;

        if (firstVis[s])
        {
            cout << 0 << '\n';
            continue;
        }

        firstVis[s] = true;
        int count{};

        if (!vis[s])
        {
            vis[s] = true;
            count++;
        }
        for (auto& x : vec[s])
        {
            if (!vis[x])
            {
                vis[x] = true;
                count++;
            }
        }
        cout << count << '\n';
    }

    return 0;
}