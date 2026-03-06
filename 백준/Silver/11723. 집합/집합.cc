using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <limits>
#include <cctype> 
#include <iomanip>

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int m;
    cin >> m;

    int s{};

    while (m--)
    {
        string cmd;
        cin >> cmd;

        if (cmd == "add")
        {
            int x;
            cin >> x;
            s |= (1 << (x - 1));
        }
        else if (cmd == "remove")
        {
            int x;
            cin >> x;

            s &= ~(1 << (x - 1));
        }
        else if (cmd == "check")
        {
            int x;
            cin >> x;
            cout << ((s & (1 << (x - 1))) ? 1 : 0) << '\n';
        }
        else if (cmd == "toggle")
        {
            int x;
            cin >> x;
            s ^= (1 << (x - 1));
        }
        else if (cmd == "all")
        {
            s = (1 << 20) - 1;
        }
        else if (cmd == "empty")
        {
            s = 0;
        }
    }
   
    return 0;
}