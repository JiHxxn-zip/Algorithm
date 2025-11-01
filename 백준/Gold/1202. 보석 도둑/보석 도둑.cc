using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> vec(n);

    // 보석
    for (int i = 0; i < n; i++)
        cin >> vec[i].second >> vec[i].first;
    
    sort(vec.rbegin(), vec.rend());

    multiset<int> bag;
    // 가방
    for (int i = 0; i < k; i++)
    {
        int q;
        cin >> q;
        bag.insert(q);
    }

    long long answer{};
    for (auto a : vec)
    {
        auto it = bag.lower_bound(a.second);
        if (it == bag.end())
            continue;

        answer += a.first;
        bag.erase(it);
    }

    cout << answer << '\n';

    return 0;
}
