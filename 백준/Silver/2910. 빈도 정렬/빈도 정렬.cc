using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <climits>
#include <cctype> 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, c;
    cin >> n >> c;
    
    unordered_map<int, long long> map; // 번호, 빈도 수 저장
    unordered_map<int, int> oder; // 해당 번호와 나온 순서 저장

    int idx{};

    for (int i = 0; i < n; i++)
    {
        int a; 
        cin >> a;

        map[a]++;

        if (oder.find(a) == oder.end())
            oder[a] = idx++;
    }

    // 정렬을 위한 vector
    vector<tuple<int, long long, int>> vec_Sort{}; // 번호, 나온 수, 나온 순서

    for (auto& a : map)
    {
        vec_Sort.push_back({ a.first, a.second, oder[a.first]});
    }


    sort(vec_Sort.begin(), vec_Sort.end(), [](auto& a, auto& b)
        {
            if (get<1>(a) != get<1>(b))
                return get<1>(a) > get<1>(b);

            return get<2>(a) < get<2>(b);
        });

    for (auto& a : vec_Sort)
    {
        for (int i = 0; i < get<1>(a); i++)
        {
            cout << get<0>(a) << ' ';
        }
    }

    return 0;
}

