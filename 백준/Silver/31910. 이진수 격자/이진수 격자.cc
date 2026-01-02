using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <climits>
#include <cctype> 

int N;
vector<vector<int>> a;
vector<vector<unsigned long long>> memo;
vector<vector<char>> vis;   // vector bool의 특수화 대체

unsigned long long solve(int i, int j) 
{
    // i, j: 0-indexed
    if (i == 0 && j == 0)
        return (unsigned long long)a[0][0];

    if (vis[i][j]) 
        return memo[i][j];
    
    vis[i][j] = 1;

    unsigned long long bestPrev;
    if (i == 0) 
        bestPrev = solve(i, j - 1);          // 첫 행: 왼쪽만
    else if (j == 0) 
        bestPrev = solve(i - 1, j);          // 첫 열: 위만
    else 
        bestPrev = max(solve(i - 1, j), solve(i, j - 1)); // 그 외: 둘 중 큰 거

    memo[i][j] = bestPrev * 2ULL + (unsigned long long)a[i][j];
    return memo[i][j];
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    a.assign(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> a[i][j];

    memo.assign(N, vector<unsigned long long>(N, 0));
    vis.assign(N, vector<char>(N, 0));

    cout << solve(N - 1, N - 1) << "\n";

    return 0;
}