#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n , k;
    cin >> n >> k;
 
    vector<pair<int, int>> vec(n);
    for (int i = 0; i < n; i++) 
        cin >> vec[i].first >> vec[i].second; 

    vector<int> dp(k + 1, 0);
    for (int i = 0; i < n; i++) 
    {
        int w = vec[i].first, v = vec[i].second;
        for (int j = k; j >= w; j--) 
        {
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }
    
    cout << dp[k];
    return 0;
}
