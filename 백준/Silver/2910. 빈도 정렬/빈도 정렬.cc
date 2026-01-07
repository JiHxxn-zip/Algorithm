#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, c;
    cin >> n >> c;

    unordered_map<int, long long> map;
    unordered_map<int, int> oder;

    
    int idx{};
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        map[a]++;
        if (oder.find(a) == oder.end())
            oder[a] = idx++;
    }

    // 갯수 값
    vector<tuple<long long, int, long long>> sort_vec;

    for (auto& p : map)
        sort_vec.push_back({ p.second, oder[p.first], p.first });

    

    sort(sort_vec.begin(), sort_vec.end(), [](auto& a, auto& b)
        {
            if (get<0>(a) != get<0>(b))
                return get<0>(a) > get<0>(b); // 빈도가 높은게 앞

            return get<1>(a) < get<1>(b);       // 먼저 나온게 앞
        });

    

    // 출력
    for (int i = 0; i < sort_vec.size(); i++)
    {
        for (int j = 0; j < get<0>(sort_vec[i]); j++)
        {
            cout << get<2>(sort_vec[i]) << ' ';
        }
    }
 
    return 0;
}

// 주어지는 수열에서 많은 순으로 정렬 vec[]++
// 먼저 나온 것이 앞에 있어야함
// - 같은 갯수도 확인해야하고, 먼저 나온 것도 기억해야함