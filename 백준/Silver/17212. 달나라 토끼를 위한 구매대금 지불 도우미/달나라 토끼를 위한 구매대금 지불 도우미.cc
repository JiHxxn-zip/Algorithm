using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
#include <cctype> 
#include <iomanip>

typedef long long ll;

vector<int> vec{ 1, 2, 5, 7 };
vector<int> memo;

int DP(int n)
{
    if (n == 0)
        return 0;

    if (memo[n] != -1)
        return memo[n];

    int ret = numeric_limits<int>::max();

    for (int x : vec)
    {
        if (x <= n)
            ret = min(ret, DP(n - x) + 1);
    }

    return memo[n] = ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    memo.assign(n + 1, -1);

    cout << DP(n);


    return 0;
}