using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <limits>
#include <cctype> 
#include <iomanip>

typedef long long ll;

int mod = 998244353;

vector<int> vec;
vector<int> memo;

int DP(int i)
{
    int& ret = memo[i];
    if (ret != -1)
        return ret;

    ll sum = 1;
    for (int j = 0; j < i; j++)
    {
        if (vec[i] > vec[j])
            sum += DP(j);
    }

    ret = static_cast<int>(sum % mod);
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    vec.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> vec[i];

    memo.assign(n, -1);

    for (int i = 0; i < n; i++)
        cout << DP(i) << ' ';
   
    return 0;
}
