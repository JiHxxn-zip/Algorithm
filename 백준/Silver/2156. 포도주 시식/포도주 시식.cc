using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
#include <cctype> 
#include <iomanip>

typedef long long ll;

int n;
vector<int> vec;
int memo[10001][3];

int DP(int x, int cnt)
{
    if (x == n)
        return 0;

    int& ret = memo[x][cnt];
    if (ret != -1)
        return ret;

    // 1. 현재 잔 안 마심
    ret = DP(x + 1, 0);

    // 2. 현재 잔 마심 (연속 2잔 미만일 때만)
    if (cnt < 2)
        ret = max(ret, vec[x] + DP(x + 1, cnt + 1));

    return ret;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;

    vec.assign(n+1, 0);
    for (int i = 0; i < n; i++)
        cin >> vec[i];

    fill(&memo[0][0], &memo[0][0] + 10001 * 3, -1);

    cout << DP(0, 0);
    return 0;
}