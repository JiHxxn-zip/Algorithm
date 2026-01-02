using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <climits>
#include <cctype> 

int arr[9];
bool vis[9];
int n;

void DFS(int depth)
{
    if (depth == n)
    {
        for (int i = 0; i < n; i++)
            cout << arr[i] << ' ';
        
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;

        arr[depth] = i;
        vis[i] = true;
        DFS(depth + 1);
        vis[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    DFS(0);

    return 0;
}

