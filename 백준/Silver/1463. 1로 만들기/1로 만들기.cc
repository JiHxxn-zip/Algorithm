#include <iostream>
#include <vector>
#include "algorithm"
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n{};
    cin >> n;
    
    // 벡터의 크기를 미리 할당시킨다. 주어진 사이즈에서 + 1 만큼 0으로 초기화
    vector<int> dp(n + 1, 0);

    for (size_t i = 2; i <= n; i++)
    {
        dp[i] = dp[i-1] + 1;

        if (i % 2 == 0)
            dp[i] = min(dp[i], dp[i / 2] + 1);
        if (i % 3 == 0)
            dp[i] = min(dp[i], dp[i / 3] + 1);
    }

    cout << dp[n];

    return 0;
}       
