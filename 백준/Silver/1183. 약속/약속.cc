#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <climits> // INT_MAX

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> vec(n);
    for (int i = 0; i < n; i++)
    {
        long long promis, end;
        cin >> promis >> end;

        vec[i] = end - promis;
    }
    sort(vec.begin(), vec.end());

    if (n % 2 == 1)
        cout << 1 << '\n';
    else
    {
        long long left = vec[n / 2 - 1];
        long long right = vec[n / 2];
        cout << right - left + 1 << '\n';
    }

    return 0;
}
