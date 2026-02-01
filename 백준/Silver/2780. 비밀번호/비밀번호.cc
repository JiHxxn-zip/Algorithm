using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <climits> // INT_MAX

typedef long long ll;

const int MOD = 1234567;
ll memo[1001][10];

vector<int> adj[10] = {
    {7},            // 0
    {2,4},          // 1
    {1,3,5},        // 2
    {2,6},          // 3
    {1,5,7},        // 4
    {2,4,6,8},      // 5
    {3,5,9},        // 6
    {4,8,0},        // 7
    {5,7,9},        // 8
    {6,8}           // 9
};

ll DP(int len, int num)
{
    if (len == 1)
        return 1;

    ll& ret = memo[len][num];
    if (ret != -1)
        return ret;
    
    ret = 0;
    for (int next : adj[num]) 
        ret = (ret + DP(len - 1, next)) % MOD;
    
    return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int t;
    cin >> t;
    
    while (t--)
    {
        int n;
        cin >> n;

        for (int i = 0; i <= 1000; i++)
            for (int j = 0; j < 10; j++)
                memo[i][j] = -1;

        ll answer{};
        for (int i = 0; i < 10; i++)
            answer = (answer + DP(n, i)) % MOD;

        cout << answer << '\n';
    }
	return 0;
}