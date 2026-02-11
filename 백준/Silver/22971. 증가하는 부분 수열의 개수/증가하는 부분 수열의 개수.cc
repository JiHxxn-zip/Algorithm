using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <limits>
#include <cctype> 
#include <iomanip>
#include <unordered_map>

typedef long long ll;

int mod = 998244353;

vector<int> vec;
vector<int> memo;
vector<char> vis;

ll DP(int i)
{
    if (vis[i])
        return memo[i];

    vis[i] = 1;

    ll answer = 1;
    for (int j = 0; j < i; j++)
    {
        if (vec[j] < vec[i])
        {
            answer += DP(j);

            if (answer >= static_cast<ll>(mod))
                answer %= mod;
        }
    }

    memo[i] = static_cast<int>(answer % mod);
    return memo[i];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vec.assign(n, 0);
    for (int i = 0; i < n; ++i) 
        cin >> vec[i];
    
    memo.assign(n, 0);
    vis.assign(n, 0);

    for (int i = 0; i < n; i++)
        cout << DP(i) << ' ';

    return 0;
}