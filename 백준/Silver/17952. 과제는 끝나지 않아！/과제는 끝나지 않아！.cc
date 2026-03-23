using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <limits>
#include <cctype> 
#include <iomanip>

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    stack<pair<int, int>> s;
    int count{};
    while (n--)
    {
        int m;
        cin >> m;

        if (m == 1)
        {
            int score, time;
            cin >> score >> time;
            s.push({ score, time - 1 });
        }
        else
        {
            // 현재 1분 추가 적립
            if (!s.empty())
            {
                auto cur = s.top();
                s.pop();
                cur.second -= 1;
                s.push(cur);
            }
        }

        if (!s.empty() && s.top().second == 0)
        {
            count += s.top().first;
            s.pop();
        }
    }

    cout << count;
    return 0;
}