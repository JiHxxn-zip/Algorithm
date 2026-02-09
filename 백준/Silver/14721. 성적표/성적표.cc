using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <limits>
#include <cctype> 
#include <iomanip>
#include <unordered_map>

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; ++i) 
        cin >> p[i].first >> p[i].second; 

    ll best = numeric_limits<ll>().max();
    int bestA = 1, bestB = 1;

    // 모든 a,b를 다 시험해보고 가장 덜 틀린 직선을 찾는다
    for (int a = 1; a <= 100; ++a) 
    {
        for (int b = 1; b <= 100; ++b) 
        {
            ll rss = 0;
            for (auto xy : p) 
            {
                // diff = y - (a * y + b)
                ll diff = xy.second - (static_cast<ll>(a) * xy.first + b);
                rss += diff * diff; // 제곱
            }
            if (rss < best) 
            {
                best = rss;
                bestA = a;
                bestB = b;
            }
        }
    }

    cout << bestA << ' ' << bestB;
    return 0;
}

