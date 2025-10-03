#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// 숫자 i를 1로 만드는 최소 연산 횟수를 저장하는 배열
int dp[1000001];
// 숫자 i에서 1로 만들기 위해 어떤 연산을 사용했는지를 기록
int before[1000001]; 


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    dp[1] = 0;
    before[1] = 0;
    for (size_t i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + 1; // 1을 더한 값이 기본적으로 최대 값
        before[i] = i - 1;

        // i 가 3으로 나누어 떨어지고, dp[i / 3] + 1보다 더 작은 값이 있다면 dp[i]를 갱신
        if (i % 3 == 0 && dp[i] > dp[i / 3] + 1)
        {
            dp[i] = dp[i / 3] + 1;
            before[i] = i / 3;
        }

        // i 가 2으로 나누어 떨어지고, dp[i / 2] + 1보다 더 작은 값이 있다면 dp[i]를 갱신
        if (i % 2 == 0 && dp[i] > dp[i / 2] + 1)
        {
            dp[i] = dp[i / 2] + 1;
            before[i] = i / 2;
        }
    }


    // before에 저장된 1이되기 위한 값을 꺼내고 출력
    cout << dp[n] << '\n';
    while (n != 0)
    {
        cout << n << ' ';
        n = before[n];
    }

    return 0;
}