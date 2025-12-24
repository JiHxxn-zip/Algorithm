using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, p;
    cin >> n >> p;
    int w, l, g;
    cin >> w >> l >> g;

    unordered_map<string, char> map;

    while (p--)
    {
        string name;
        char result;
        cin >> name >> result;

        map.insert({name, result});
    }

    int result{};
    while (n--)
    {
        string name;
        cin >> name;

        if (map[name] == 'W')
        {
            result += w;
            if (result >= g)
                break;
        }
        else
        {
            result -= l;
            if (result < 0)
                result = 0;
        }
    }

    if (result >= g)
        cout << "I AM NOT IRONMAN!!";
    else
        cout << "I AM IRONMAN!!";

    return 0;
}