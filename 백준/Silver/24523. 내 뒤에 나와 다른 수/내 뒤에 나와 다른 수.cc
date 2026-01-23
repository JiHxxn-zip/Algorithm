using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <queue>
#include <climits>
#include <cctype> 
#include <iomanip>

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i];

    vector<int> ans(n, -1);

    // i = n-1(마지막)은 항상 -1
    for (int i = n - 2; i >= 0; --i) 
    {
        if (a[i] != a[i + 1]) 
            ans[i] = i + 2;      // 1-based로 i+1 위치 => i+2
        else 
            ans[i] = ans[i + 1];
    }

    for (int i = 0; i < n; i++) 
        cout << ans[i] << (i + 1 == n ? '\n' : ' ');

    return 0;
}