using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cctype> 
#include <iomanip>
#include <unordered_map>
#include <sstream>

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<string> name(n);
    unordered_map<string, int> map;
    for (int i = 0; i < n; i++)
    {
        cin >> name[i];
        map[name[i]] = 0;
    }

    cin.ignore(); // 버퍼 지우기

    for (int i = 0; i < n; i++)
    {
        string line;
        getline(cin, line);

        stringstream ss(line);
        string token;
        while (ss >> token)
        {
            if (map.find(token) != map.end())
                map[token]++;
        }
    }

    vector<pair<string, int>> v;
    v.reserve(n);
    for (auto& nm : name)
    {
        v.push_back({ nm, map[nm] });
    }

    sort(v.begin(), v.end(), [](const auto& a, const auto& b)
        {
            if (a.second != b.second)
                return a.second > b.second;
            return a.first < b.first;
        });


    for (auto a : v)
        cout << a.first << ' ' << a.second << '\n';

	return 0;
}