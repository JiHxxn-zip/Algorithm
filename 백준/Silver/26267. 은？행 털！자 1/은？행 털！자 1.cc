using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
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

    unordered_map<ll, ll> map;
    ll answer{};
    for (int i = 0; i < n; i++)
    {
        int x, t, c;
        cin >> x >> t >> c;

        map[t - x] += c;
        answer = max(answer, map[t - x]);
    }

    cout << answer;

    return 0;
}
