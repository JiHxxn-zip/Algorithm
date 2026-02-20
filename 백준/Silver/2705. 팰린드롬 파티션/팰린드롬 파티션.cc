using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <limits>
#include <cctype> 
#include <iomanip>

typedef long long ll;

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
        int n;
        cin >> n;

        memo.assign(1001, -1);
        cout << DP(n) << '\n';
    }

    return 0;
}