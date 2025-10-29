using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int k;
        cin >> k;
        multiset<int> ms;

        for (int i = 0; i < k; i++)
        {
            char com;
            cin >> com;
            if (com == 'D')
            {
                int q;
                cin >> q;
                if (ms.empty())
                    continue;
                if (q == 1)
                    ms.erase(prev(ms.end()));
                else
                    ms.erase(ms.begin());
            }
            else
            {
                int q;
                cin >> q;
                ms.insert(q);
            }
        }
        if (ms.empty())
            cout << "EMPTY\n";
        else
            cout << *prev(ms.end()) << ' ' << *ms.begin() << '\n';
    }

    return 0;
}

// d가 나왔을 떄를 구분