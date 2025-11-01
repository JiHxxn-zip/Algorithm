using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    unordered_map<int, string> i2s_map;
    unordered_map<string, int> s2i_map;

    i2s_map[0] = "{}";
    i2s_map[1] = "{{}}";
    s2i_map[i2s_map[0]] = 0;
    s2i_map[i2s_map[1]] = 1;

    for (int i = 2; i < 16; i++)
    {
        i2s_map[i] = "{";
        for (int j = 0; j < i; j++)
        {
            i2s_map[i] += i2s_map[j] + ",";
        }
        i2s_map[i].back() = '}';
        s2i_map[i2s_map[i]] = i;
    }
    
    string a{}, b{};
    while (t--)
    {
        cin >> a >> b;
        cout << i2s_map[s2i_map[a] + s2i_map[b]] << '\n';
    }

    return 0;
}
