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

    vector<int> vec(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    sort(vec.rbegin(), vec.rend());

    deque<pair<int, int>> q;
    int temp = -1;
    for (int x : vec)
    {
        if (!q.empty() && q.back().first == x)
        {
            q.back().second++;
        }
        else
        {
            q.push_back({ x, 1 });
        }
    }

    ll count{};

    for (int i = 0; i < d; i++)
    {
        if (q.empty() || q.front().first == 0)
            break;

        auto cur = q.front();
        q.pop_front();

        count += cur.second;

        int nextHeight = cur.first - 1;

        if (nextHeight == 0)
        {
            q.push_back({ 0, cur.second });
        }
        else if (!q.empty() && q.front().first == nextHeight)
        {
            q.front().second += cur.second;
        }
        else
        {
            q.push_front({ nextHeight, cur.second });
        }
    }

    cout << count;
    return 0;
}