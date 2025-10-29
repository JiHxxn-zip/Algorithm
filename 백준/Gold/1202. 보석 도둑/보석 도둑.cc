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

    vector<pair<int, int>>vec(n);

    for (int i = 0; i < n; i++)
    {
        cin >> vec[i].second >> vec[i].first;
    }
    sort(vec.rbegin(), vec.rend());

    multiset<int> bag;
    int c;
    for (int i = 0; i < k; i++)
    {
        cin >> c;
        bag.insert(c);
    }

    long long answer{};

    for (auto jweInfo : vec)
    {
        auto it = bag.lower_bound(jweInfo.second);
        if (it == bag.end())
            continue;

        answer += jweInfo.first;
        bag.erase(it);
    }

    cout << answer << '\n';
    return 0;
}

// 크기가 가장 작은 가방부터
// - 자신이 담을 수 있는 가장 비싼 보석부터 담기