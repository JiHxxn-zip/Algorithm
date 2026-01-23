using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <queue>
#include <climits>
#include <cctype> 
#include <iomanip>

typedef long long ll;

int n;
vector<ll> memo; 

ll DP(int k)
{
    if (k == 0)
        return 1;

    if (memo[k] != -1)
        return memo[k];

    ll sum{};
    for (int i = 0; i <= k-1; i++)
        sum += DP(i) * DP(k - 1 - i);

    return memo[k] = sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    memo.assign(n + 1, -1);

    cout << DP(n);

    return 0;
}
