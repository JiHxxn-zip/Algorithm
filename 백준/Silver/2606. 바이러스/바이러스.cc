#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "algorithm"
using namespace std;

bool vis[105];
vector<int> board[105];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int comNum, comPair;
    cin >> comNum;
    cin >> comPair;

    for (size_t i = 0; i < comPair; i++)
    {
        int a, b;
        cin >> a >> b;

        board[a].push_back(b);
        board[b].push_back(a);
    }
    
    int count{};

    queue<int> q;
    q.push(1);
    vis[1] = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int a : board[cur])
        {
            if (vis[a] == true) continue;
            vis[a] = true;
            count++;
            q.push(a);
        }
    }
    cout << count;
    return 0;
}       
