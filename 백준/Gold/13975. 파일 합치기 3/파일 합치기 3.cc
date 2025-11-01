using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

typedef long long ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    
    while (t--)
    {
        int k;
        cin >> k;
        priority_queue<ll, vector<ll>, greater<ll>> pq;

        ll a{};
        for (int i = 0; i < k; i++)
        {
            cin >> a;
            pq.push(a);
        }

        ll answer{};
        while (pq.size() > 1)
        {
            ll a = pq.top();
            pq.pop();
            ll b = pq.top();
            pq.pop();
            answer += a + b;

            pq.push(a + b);
        }
        cout << answer << '\n';
    }

    return 0;
}
