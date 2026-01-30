using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>
#include <cctype> 
#include <iomanip>
#include <deque>

typedef long long ll;

ll n;
vector<ll> memo;

ll DP(int x)
{
    if (x == 0)
        return 0;

    ll& ret = memo[x];
    if (ret != -1)
        return ret;

    ret = 1;
    for (int i = 1; i <= x/2; i++)
        ret += DP(i);

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        memo.assign(1001, -1);
        cout << DP(n) << '\n';
    }

    return 0;
}
