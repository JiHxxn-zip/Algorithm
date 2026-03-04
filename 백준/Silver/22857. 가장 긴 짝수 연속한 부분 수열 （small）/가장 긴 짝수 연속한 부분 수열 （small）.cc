using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <limits>
#include <cctype> 
#include <iomanip>

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int& x : a) cin >> x;

    int left = 0;
    int odd = 0;
    int even = 0;
    int ans = 0;

    for (int right = 0; right < n; right++)
    {
        if (a[right] % 2) odd++;
        else even++;

        while (odd > k)
        {
            if (a[left] % 2) odd--;
            else even--;
            left++;
        }

        ans = max(ans, even);
    }

    cout << ans;
    return 0;
}