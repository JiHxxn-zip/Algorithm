using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <limits>
#include <cctype> 
#include <iomanip>

typedef long long ll;

int n, m;
vector<vector<int>> vec;
vector<vector<vector<int>>> memo;

int DP(int row, int col, int prevDir)
{
    if (col < 0 || col >= m)
        return numeric_limits<int>::max();

    if (row == n - 1)
        return vec[row][col];

    int& ret = memo[row][col][prevDir];
    if (ret != -1)
        return ret;
    
    ret = numeric_limits<int>::max();

    if (prevDir != 0)
        ret = min(ret, DP(row + 1, col - 1, 0));
    if (prevDir != 1)
        ret = min(ret, DP(row + 1, col, 1));
    if (prevDir != 2)
        ret = min(ret, DP(row + 1, col + 1, 2));

    return ret += vec[row][col];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   
    cin >> n >> m;
    
    vec.assign(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> vec[i][j];

    memo.assign(n, vector<vector<int>>(m, vector<int>(200, -1)));

    int answer = numeric_limits<int>::max();
    for (int i = 0; i < m; i++)
        answer = min(answer, DP(0, i, 3));

    cout << answer;
    return 0;
}

// 아래로 3방향을 움직이고 이전 방향과 달라야하며, min값 추출