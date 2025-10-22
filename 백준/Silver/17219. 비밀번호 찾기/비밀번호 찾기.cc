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
    for (int i = 0; i < n; i++)
    {
        string a, b;
        cin >> a >> b;

        map[a] = b;
    }

    for (int i = 0; i < m; i++)
    {
        string a;
        cin >> a;
        cout << map[a] << '\n';
    }
    return 0;
}

