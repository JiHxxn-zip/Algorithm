using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cctype> 
#include <iomanip>
#include <unordered_map>

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int total = n;
    unordered_map<ll, int> map;

    for (int i = 0; i < n; i++)
    {
        ll c;
        cin >> c;
        map[c]++;
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        // A
        int aCnt;
        cin >> aCnt;

        unordered_map<ll, int> need;
        for (int a = 0; a < aCnt; a++)
        {
            ll x;
            cin >> x;
            need[x]++;
        }

        int bCnt;
        cin >> bCnt;

        // B
        unordered_map<long long, int> add;
        for (int b = 0; b < bCnt; b++)
        {
            ll x;
            cin >> x;
            add[x]++;
        }

        // A를 전부 먹을 수 있는지 확인
        bool ok = true;
        for (auto& p : need)
        {
            auto it = map.find(p.first);
            if (it == map.end() || it->second < p.second)
            {
                ok = false;
                break;
            }
        }

        // 가능하면 A를 빼고 B를 더함
        if (ok)
        {
            for (auto& p : need)
            {
                map[p.first] -= p.second;
                if (map[p.first] == 0) map.erase(p.first);
            }

            for (auto& p : add)
                map[p.first] += p.second;
        }
    }

    // 출력: 남은 총 개수
    vector<int> vec;
    for (auto& a : map)
        while (a.second--)
            vec.push_back(a.first);

    cout << vec.size() << '\n';
    for (auto& a : vec)
        cout << a << ' ';
}
