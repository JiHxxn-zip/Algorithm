using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <climits>
#include <cctype> 

int n, m;
vector<vector<int>> a;
vector<vector<int>> dp; // -1이면 미계산

int Solve(int r, int c)
{
    // 기저: 맵 밖이면 더 못 먹음
    if (r >= n || c >= m) return 0;

    int& ret = dp[r][c];
    if (ret != -1) return ret;

    // 현재 칸 먹고, 아래/오른쪽 중 최대
    ret = a[r][c] + max(Solve(r + 1, c), Solve(r, c + 1));
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    a.assign(n, vector<int>(m));
    dp.assign(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
            cin >> a[i][j];
    }

    cout << Solve(0, 0) << "\n";

    return 0;
}
