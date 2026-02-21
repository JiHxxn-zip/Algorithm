using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <limits>
#include <cctype> 
#include <iomanip>

typedef long long ll;

int n, m;
vector<int> answer;
vector<bool> vis;

void DFS(int depth)
{
    if (depth == m)
    {
        for (auto x : answer)
            cout << x << ' ';
        
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;

        if (depth == 0 || answer[depth - 1] < i)
        {
            answer[depth] = i;

            vis[i] = true;
            DFS(depth + 1);
            vis[i] = false;
        }
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    
    answer.assign(m, 0);
    vis.assign(n+1, false);
    
    DFS(0);
    return 0;
}
