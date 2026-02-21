using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <limits>
#include <cctype> 
#include <iomanip>

typedef long long ll;

ll c;
vector<ll> memo;
const ll MOD = 1000000007;

ll DP(int n)
{
    ll& ret = memo[n];
    if (ret != -1)
        return ret;

    if (n < 2)
        return ret = 1;

    ret = (DP(n - 2) + DP(n - 1) + 1) % MOD;
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    memo.assign(51, -1);

    cout << DP(n);
    return 0;
}
