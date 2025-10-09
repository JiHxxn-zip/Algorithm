#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    vector < pair<int, int>> vec(n);

    for (int i = 0; i < n; i++)
    {
        int f, l;
        cin >> f >> l;

        vec[i] = { l, f };
    }

    sort(vec.begin(), vec.end());

    int cnt{}, temp{};
    for (int i = 0; i < n; i++)
    {
        if (temp > vec[i].second)
            continue;

        temp = vec[i].first;
        ++cnt;
    }

    cout << cnt;

    return 0;
}
