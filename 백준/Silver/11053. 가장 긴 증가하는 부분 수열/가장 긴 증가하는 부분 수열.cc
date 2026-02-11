using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <limits>
#include <cctype> 
#include <iomanip>
#include <unordered_map>

typedef long long ll;
int n;
vector<int> vec;
vector<int> memo;

int DP(int i)
{
    int& ret = memo[i];
    if (ret != -1)
        return ret;

    ret = 1;

    for (int j = 0; j < i; ++j)
    {
        if (vec[i] > vec[j])
            ret = max(ret, 1 + DP(j));
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    vec.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    
    memo.assign(n, -1);
    
    int answer{};
    for (int i = 0; i < n; i++)
        answer = max(answer, DP(i));

    cout << answer;

    return 0;
}