using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>

int n, k;
int cnt = 0;
bool found = false;

void DFS(int sum, vector<int>& path)
{
    if (found)
        return;

    if (sum > n)
        return;

    if (sum == n)
    {
        cnt++;
        if (cnt == k)
        {
            for (int i = 0; i < path.size(); i++)
            {
                cout << path[i];
                if (i != path.size() - 1)
                    cout << "+";
            }
            found = true;
        }
        return;
    }

    for (int i = 1; i <= 3 ; i++)
    {
        path.push_back(i);
        DFS(sum + i, path);
        path.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    vector<int> path;
    DFS(0, path);

    if (!found)
        cout << -1;

    return 0;
}