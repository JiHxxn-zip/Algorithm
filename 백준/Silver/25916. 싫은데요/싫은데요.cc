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

    int n;
    ll m;
    cin >> n >> m;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i];

    ll ans = 0;
    ll sum = 0;
    int r = 0;

    for (int l = 0; l < n; l++) 
    {
        while (r < n && sum + a[r] <= m) 
        {
            sum += a[r];
            r++;
        }
        ans = max(ans, sum);

        // 다음 l로 이동: 현재 l을 구간에서 제거
        if (r == l) 
        {
            // 구간이 비어있고 a[l] 자체가 m 초과인 경우 등
            r++;
        }
        else 
            sum -= a[l];
    }

    cout << ans;
    return 0;
}
 