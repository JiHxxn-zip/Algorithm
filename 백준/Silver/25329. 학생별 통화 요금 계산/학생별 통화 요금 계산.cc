using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <limits>
#include <cctype> 
#include <iomanip>

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    map<string, int> map;
    for (int i = 0; i < n; i++)
    {
        string time;
        string name;

        cin >> time >> name;
        
        int minute = stoi(time.substr(0, 2));
        int second = stoi(time.substr(3, 2));

        int total = minute * 60 + second;

        map[name] += total;
    }

    for (auto& x : map)
    {
        int total = x.second;

        int price{};
        if (total >= 100)
        {
            total -= 100;
            price = 10;
        }
        else
        {
            total = 0;
            price = 10;
        }

        price += (total / 50) * 3;
        price += total % 50 != 0 ? 3 : 0;

        x.second = price;
    }

    vector<pair<int, string>> vec(map.size());
    int count{};
    for (auto& x : map)
    {
        vec[count] = { x.second, x.first };
        count++;
    }

    sort(vec.begin(), vec.end(),
        [](const pair<int, string>& a, const pair<int, string>& b)
        {
            if (a.first == b.first)
                return a.second < b.second;   // 이름 오름차순
            return a.first > b.first;        // 가격 내림차순
        });

    for (auto& x : vec)
        cout << x.second << ' ' << x.first << '\n';
    return 0;
}

// 자료구조, 그래프 탐색, 그리디/DP/백트래킹, 
// LIS, 그래프, 구현, 이분탐색, 문자열, 비트마스크, 누적합