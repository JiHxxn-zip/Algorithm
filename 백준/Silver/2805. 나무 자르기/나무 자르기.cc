using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <climits>
#include <cctype> 
#include <iomanip>

typedef long long ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vector<int> vec(n);
    int left{}, right{};
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
        right = max(right, vec[i]);
    }
    
    int result{};
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        ll tmp{};
        for (int i = 0; i < n; i++)
        {
            if (vec[i] > mid)
                tmp += vec[i] - mid;
        }

        if (tmp >= m)
        {
            result = max(mid, result);
            left = mid + 1;
        }
        else
            right = mid - 1;

    }

    cout << result;
    return 0;
}


// left right
// right 값을 주어진 수에서 가장 큰 값으로 ex 20
// left를 값을 주어진 수에서 가장 작은 값으로 ex 10