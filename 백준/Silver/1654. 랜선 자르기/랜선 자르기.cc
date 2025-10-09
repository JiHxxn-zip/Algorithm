#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, n;
    cin >> k >> n;

    vector<int> vec(k);
    int max_len{};
    for (int i = 0; i < k; i++)
    {
        cin >> vec[i];
        max_len = max(max_len, vec[i]);
    }

    long long start = 1;
    long long end = max_len;
    long long result{};

    while (start <= end)
    {
        long long mid = (start + end) / 2;
        long long count{};

        for (int i = 0; i < k; i++)
            count += vec[i] / mid;

        if (count >= n)
        {
            result = mid;
            start = mid + 1;
        }
        else
            end = mid - 1;
    }

    cout << result;
    return 0;
}