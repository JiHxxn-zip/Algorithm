using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <unordered_map>
#include <climits> // INT_MAX

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int L, N, K, ans;
    string s[20];

    cin >> L >> N;
    for (int i = 0; i < N; i++) 
        cin >> s[i];
    cin >> K;

    unordered_map<string, int> mp;

    for (int i = 0; i < N; i++) 
    {
        for (int k = 0; k + K <= L; k++) 
            mp[s[i].substr(k, K)]++;
    }

    for (auto& p : mp) 
        ans = max(ans, p.second);

    cout << ans;
    
    return 0;
}