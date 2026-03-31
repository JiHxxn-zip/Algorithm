using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits>
#include <cctype> 
#include <iomanip>

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, d;
    cin >> n >> d;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    sort(vec.begin(), vec.end());

    deque<pair<int, int>> dq;
    for (int i = 0; i < n; i++)
    {
        if (!dq.empty() && dq.front().first == vec[i])
        {
            dq.front().second++;
            continue;
        }

        dq.push_front({ vec[i], 1 });
    }

    ll count{};
    for (int i = 0; i < d; i++)
    {
        if (dq.empty() || dq.front().first == 0)
            break;

        auto cur = dq.front();
        dq.pop_front();

        count += cur.second;
        ll nextHeight = cur.first - 1;

        if (nextHeight == 0)
            dq.push_front({ 0, cur.second });
        else if (!dq.empty() && nextHeight == dq.front().first)
            dq.front().second += cur.second;
        else
            dq.push_front({ nextHeight, cur.second });
    }

    cout << count;
    return 0;
}
