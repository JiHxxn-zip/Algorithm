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

    int n, m;
    cin >> n >> m;

    unordered_map<string, string> map;

    string key{}, value{};
    for (int i = 0; i < n; i++)
    {
        cin >> key >> value;

        map.insert({key, value});
    }

    string output{};
    for (int i = 0; i < m; i++)
    {
        cin >> output;
        cout << map[output] << '\n';
    }
    return 0;
}