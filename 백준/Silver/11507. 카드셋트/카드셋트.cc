using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <limits>
#include <cctype> 
#include <iomanip>
#include <unordered_map>

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    unordered_map<char, int> map;
    unordered_map<string, int> dobleChak;

    string key{};
    key = s[0];
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'P' || s[i] == 'K' || s[i] == 'H' || s[i] == 'T')
        {
            map[s[i]]++;
            key = s[i];
        }
        else
        {
            key += s[i];
            if(key.size() == 3)
                dobleChak[key]++;
        }
    }

    for (auto& a : dobleChak)
    {
        if (a.second > 1)
        {
            cout << "GRESKA";
            return 0;
        }
    }

    char countList[4] {'P', 'K', 'H', 'T'};

    for (int i = 0; i < 4; i++)
    {
        cout << 13 - map[countList[i]] << ' ';
    }


    return 0;
}
