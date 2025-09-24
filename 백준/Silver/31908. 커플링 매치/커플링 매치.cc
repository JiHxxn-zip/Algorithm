#include <iostream>
#include <vector>
#include <unordered_map>
#include "algorithm"
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // ring을 key값이 포인트
    unordered_map<string, vector<string>> map;

    int n{};
    cin >> n;

    for (size_t i = 0; i < n; i++)
    {
        string name, ring;
        cin >> name >> ring;

        if (ring != "-")
        {
            map[ring].push_back(name);
        }
    }

    vector<pair<string, string>> couple;

    for (auto a : map)
    {
        vector<string> names = a.second;
        if (names.size() == 2)
        {
            for (size_t i = 0; i < names.size(); i++)
            {
                for (size_t j = i+1; j < names.size(); j++)
                {
                    couple.push_back(pair<string, string>(names[i], names[j]));
                }
            }
        }
    }

    cout << couple.size() << '\n';

    for (size_t i = 0; i < couple.size(); i++)
        cout << couple[i].first << ' ' << couple[i].second << '\n';

    return 0;
}
