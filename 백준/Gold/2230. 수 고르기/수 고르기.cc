#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int mn = INT_MAX;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];

    sort(vec.begin(), vec.end());
    
    int en{};
    for (int i = 0; i < n; i++)
    {
        while (en < n && vec[en] - vec[i] < m)
            en++;

        if (en == n)
            break;

        mn = min(mn, vec[en] - vec[i]);
    }

    cout << mn;

    return 0;
}