using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, newScore, p;
    cin >> n >> newScore >> p;

    if (n == 0)
    {
        cout << 1;
        return 0;
    }

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];

    sort(vec.begin(), vec.end(), greater<int>());

    if (n == p && vec[n - 1] >= newScore)
    {
        cout << -1;
        return 0;
    }
    
    for (int i = 0; i < n; i++)
    {
        if (vec[i] <= newScore)
        {
            cout << i + 1;
            return 0;
        }
    }

    cout << n + 1;

    return 0;
}