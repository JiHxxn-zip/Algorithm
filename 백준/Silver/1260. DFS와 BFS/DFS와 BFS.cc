#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "algorithm"
using namespace std;

vector<int> board[1001];
bool vis[1001];

int num, row, start;

void DFS(int n)
{
    cout << n << " ";

    vis[n] = true;

    for (int a : board[n])
        if (!vis[a])
            DFS(a);
}

void BFS(int n)
{
    queue<int> q;
    q.push(n);
    vis[n] = true;

    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        cout << cur << " ";

        for (int a : board[cur])
        {
            if (!vis[a])
            {
                vis[a] = true;
                q.push(a);
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> num >> row >> start;

    for (size_t i = 0; i < row; i++)
    {
        int a, b;
        cin >> a >> b;
        board[a].push_back(b);
        board[b].push_back(a);
    }

    for (size_t i = 1; i <= num; i++)
    {
        sort(board[i].begin(), board[i].end());
    }

    fill(begin(vis), end(vis), false);
    DFS(start);
    cout << "\n";

    fill(begin(vis), end(vis), false);
    BFS(start);

    return 0;
}       
