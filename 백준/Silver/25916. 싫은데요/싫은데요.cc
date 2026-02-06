using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cctype> 
#include <iomanip>

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    
    vector<ll> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];

    int en{};
    ll answer{}, total{};

    for (int st = 0; st < n; st++)
    {
        while (en < n && total + vec[en] <= m)
        {
            total += vec[en];
            en++;
        }

        answer = max(answer, total);
        total -= vec[st];
    }

    cout << answer;

    return 0;
}
