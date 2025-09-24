#include <iostream>
#include <vector>
#include "algorithm"
using namespace std;

int answer;
int sum;

bool vis[21];
int board[21];

int n, s;

void DFS(int curDepth, int x)
{
    if (sum == s && curDepth != 0)
        answer++;

    for (int i = 0; i < n; i++)
    {
        if (vis[i] || x > i) 
            continue;		// 이미 합을 구했던 부분수열은 고려하지 않음

        vis[i] = true;
        sum += board[i];
        DFS(curDepth + 1, i);

        vis[i] = false;
        sum -= board[i];
    }

    return;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    for (size_t i = 0; i < n; i++)
        cin >> board[i];

    DFS(0, 0);

    cout << answer;

    return 0;
}
