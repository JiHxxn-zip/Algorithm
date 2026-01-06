using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <climits>
#include <cctype> 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    string board;
    cin >> board;

    // 바텀업 방식으로
    vector<char> dp(n, 0);

    dp[0] = 1;

    for (int i = 1; i < n; i++)
    {
        if (board[i] == '#')
        {
            dp[i] = 0;
            continue;
        }

        if (dp[i - 1])
            dp[i] = 1;
        else if (i - k >= 0 && dp[i - k])
            dp[i] = 1;
    }

    cout << (dp[n - 1] ? "YES" : "NO");

    return 0;
}
