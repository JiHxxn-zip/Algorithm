#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, n;
    cin >> k >> n;

    vector<int> vec(k);
    int mx{};
    for (int i = 0; i < k; i++)
    {
        cin >> vec[i];
        mx = max(mx, vec[i]);
    }

    ll start = 1;
    ll end = mx;
    ll result{};

    while (start <= end)
    {
        ll mid = (start + end) / 2;
        ll count{};

        for (int i = 0; i < k; i++)
            count += vec[i] / mid;

        if (count >= n)
        {
            start = mid + 1;
            result = mid;
        }
        else
            end = mid - 1;

    }

    cout << result;

    return 0;
}