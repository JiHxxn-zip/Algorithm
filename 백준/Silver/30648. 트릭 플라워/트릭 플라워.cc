using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <limits>
#include <cctype> 
#include <iomanip>
#include <map>

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    map<pair<int, int>, int> m;

    pair<int, int> xy;
    cin >> xy.first >> xy.second;
    m[{xy.first, xy.second}] = 1;

    int r;
    cin >> r;

    int count{};
    while (true)
    {
        if (xy.first + 1 + xy.second + 1 < r)
        {
            xy.first += 1;
            xy.second += 1;

            m[{xy.first, xy.second}] += 1;
        }
        else
        {
            xy.first /= 2;
            xy.second /= 2;

            m[{xy.first, xy.second}] += 1;
        }

        count++;
        if (m[{xy.first, xy.second}] == 2)
            break;
    }

    cout << count;
    return 0;
}