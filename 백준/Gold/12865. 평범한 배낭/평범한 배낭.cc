#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n{}, k{};
    cin >> n >> k;

    vector<int> w, v;
    w.reserve(n + 1);
    v.reserve(n + 1);

    int w_t{}, v_t{};
    for (int i = 0; i < n; i++)
    {
        cin >> w_t >> v_t;
        w.push_back(w_t);
        v.push_back(v_t);
    }

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (j < w[i - 1])  // 무게 초과 시
                dp[i][j] = dp[i - 1][j];
            else               // 아이템을 담을 수 있을 때
                dp[i][j] = max(dp[i - 1][j], v[i - 1] + dp[i - 1][j - w[i - 1]]);
        }
    }

    cout << dp[n][k];

    return 0;
}

