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
    cin >>n;

    while (n--)
    {
        unordered_map<string, int> map;
        int m;
        cin >> m;

        for (int i = 0; i < m; i++)
        {
            string a, b;
            cin >> a >> b;

            map[b]++;
        }

        int answer = 1;
        for (auto a : map)
            answer *= a.second + 1;

        cout << answer - 1 << '\n';
    }
    return 0;
}

