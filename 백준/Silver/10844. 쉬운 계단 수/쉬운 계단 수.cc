using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <limits>
#include <cctype> 
#include <iomanip>

typedef long long ll;

vector<vector<int>> memo;
int mod = 1000000000;

int DP(int len, int last) 
{
    if (len == 1)
        return (last == 0 ? 0 : 1);

    int& ret = memo[len][last];
    if (ret != -1)
        return ret;

    ret = 0;

    // 이전 숫자: last-1
    if (last > 0)
        ret = (ret + DP(len -1, last -1)) % mod;

    // 이전 숫자: last+1
    if (last < 9)
        ret = (ret + DP(len - 1, last + 1)) % mod;

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    memo.assign(n+1, vector<int>(10, -1));

    ll answer{};
    for (int i = 0; i <= 9; i++)
        answer = (answer + DP(n, i)) % mod;
    
    cout<< answer;
    return 0;
}