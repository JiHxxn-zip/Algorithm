using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    while (n--)
    {
        int ti;
        cin >> ti;

        map<long long, long long> map;
        for (int i = 0; i < ti; ++i)
        {
            long long a;
            cin >> a;
            map[a]++;
        }

        long long mx = -1;
        long long result{};
        for (auto &a : map)
        {
            if (mx < a.second)
            {
                mx = a.second;
                result = a.first;       
            }
        }

        if (mx > ti / 2)
            cout << result << '\n';
        else
            cout << "SYJKGW" << '\n';
    }

    return 0;
}
