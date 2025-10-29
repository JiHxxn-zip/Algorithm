using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    priority_queue<int>pq;

    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x == 0)
        {
            if (pq.empty())
            {
                cout << 0 << '\n';
                continue;
            }

            cout << pq.top() << '\n';
            pq.pop();
        }
        else
        {
            pq.push(x);
        }
    }

    return 0;
}