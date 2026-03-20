using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
#include <cctype> 
#include <iomanip>

typedef long long ll;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    // 집, 길, 횟수
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

    vector<bool> vec_Chack(n+1, false);
    vector<bool> firstChack(n+1, false);
    while (q--)
    {
        int x;
        cin >> x;

        if (firstChack[x])
        {
            cout << 0 << '\n';
            continue;
        }

        firstChack[x] = true;

        int cnt{};
        if (!vec_Chack[x])
        {
            vec_Chack[x] = true;
            cnt++;
        }

        for (auto& a : vec[x])
        {
            if (!vec_Chack[a])
            {
                vec_Chack[a] = true;
                cnt++;
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}