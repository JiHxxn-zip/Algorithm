using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <limits>
#include <cctype> 
#include <iomanip>

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
   
    vector<pair<int, int>> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i].first >> vec[i].second;
    
    ll best = numeric_limits<ll>::max();
    ll bestA = 1, bestB = 1;

    for (int i = 1; i <= 100; i++)
    {
        for (int j = 1; j <= 100; j++)
        {
            ll rss{};
            for (auto xy : vec)
            {
                ll diff = xy.second - (static_cast<ll>(i) * xy.first + j);
                rss += diff * diff;
            }
            if (rss < best)
            {
                best = rss;
                bestA = i;
                bestB = j;
            }
        }
    }

    cout << bestA << ' ' << bestB;
    return 0;
}
