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

    int n, s;
    cin >> n >> s;

    vector<int> vec(n);

    for (int i = 0; i < n; i++)
        cin >> vec[i];
    
    int en{};
    int total = vec[0];

    for (int i = 0; i < n; i++)
    {
        while (en < n && total < s)
        {
            en++;
            if(en != n)
                total += vec[en];
        }

        if (en == n)
            break;

        mn = min(mn, en - i + 1);
        total -= vec[i];
    }

    if (mn == INT_MAX)
        mn = 0;

    cout << mn;

    return 0;
}