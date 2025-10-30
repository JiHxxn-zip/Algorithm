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

    int n;
    cin >> n;

    unordered_map<int, string> i2s_map;
    unordered_map<string, int> s2i_map;
    i2s_map.insert({0, "{}"});
    s2i_map.insert({"{}", 0});
    i2s_map.insert({1, "{{}}"});
    s2i_map.insert({"{{}}", 1});


    for (int i = 2; i < 16; i++)
    {
        string s = "{";
        for (int j = 0; j < i; j++)
        {
            s += i2s_map[j];
            if (j != i - 1)
                s += ",";
        }
        s += "}";

        i2s_map[i] = s;
        s2i_map[s] = i;
    }

    string a{}, b{};
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        
        int a1{}, b1{};
        a1 = s2i_map[a];
        b1 = s2i_map[b];

        cout << i2s_map[a1 + b1] << '\n';
    }
   
    return 0;
}

