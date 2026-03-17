using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <limits>
#include <iomanip> // 소숫점 제한


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, c;
    cin >> n >> c;

    unordered_map<int, int> map;
    unordered_map<int, int> oder;
    int idx{};
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        map[x]++;

        if (oder.find(x) == oder.end())
            oder[x] = idx++;
    }

    vector<tuple<int, int, int>> vec; // 숫자, 나온 횟수, 등장 순서
    
    for (auto& x : map)
        vec.push_back({x.first, x.second, oder[x.first]});

    sort(vec.begin(), vec.end(), [](auto& a, auto& b) 
        {
            if (get<1>(a) == get<1>(b))
                return get<2>(a) < get<2>(b);

            return get<1>(a) > get<1>(b);
        });

    for (auto& x : vec)
    {
        for (int i = 0; i < get<1>(x); i++)
            cout << get<0>(x) << ' ';
    }

    return 0;
}