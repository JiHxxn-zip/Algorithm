#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int dp[1000001];
int before[1000001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int x;
    cin >> x;

    dp[1] = 0;
    before[1] = 0;

    for (int i = 2; i <= x; i++)
    {
        dp[i] = dp[i - 1] + 1;
        before[i] = i - 1;

        if (i % 3 == 0 && dp[i] > dp[i / 3] + 1)
        {
            dp[i] = dp[i / 3] + 1;
            before[i] = i / 3;
        }

        if (i % 2 == 0 && dp[i] > dp[i / 2] + 1)
        {
            dp[i] = dp[i / 2] + 1;
            before[i] = i / 2;
        }
    }

    cout << dp[x] << '\n';

    while (x != 0)
    {
        cout << x << ' ';
        x = before[x];
    }

    return 0;
}