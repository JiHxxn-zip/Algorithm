using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
#include <cctype> 
#include <iomanip>

typedef long long ll;

int n, k;
int cnt = 0;
int found = false;

void DFS(int sum, vector<int>& vec)
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
            for (int i = 0; i < vec.size(); i++)
            {
                cout << vec[i];
                if (i != vec.size() - 1)
                    cout << '+';
            }
            found = true;
        }
        return;
    }

    for (int i = 1; i <= 3; i++)
    {
        vec.push_back(i);
        DFS(sum + i, vec);
        vec.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> k;

    vector<int> vec;
    DFS(0, vec);

    if (!found)
        cout << -1;

    return 0;
}