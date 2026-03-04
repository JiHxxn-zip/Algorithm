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

    int N, M;
    cin >> N >> M;

    vector<int> train(N + 1, 0);

    while (M--)
    {
        int cmd;
        cin >> cmd;

        if (cmd == 1)
        {
            int i, x;
            cin >> i >> x;
            train[i] |= (1 << (x - 1));
        }
        else if (cmd == 2)
        {
            int i, x;
            cin >> i >> x;
            train[i] &= ~(1 << (x - 1));
        }
        else if (cmd == 3)
        {
            int i;
            cin >> i;
            train[i] <<= 1;
            train[i] &= (1 << 20) - 1;
        }
        else if (cmd == 4)
        {
            int i;
            cin >> i;
            train[i] >>= 1;
        }
    }

    set<int> s;

    for (int i = 1; i <= N; i++)
        s.insert(train[i]);

    cout << s.size();
    return 0;
}