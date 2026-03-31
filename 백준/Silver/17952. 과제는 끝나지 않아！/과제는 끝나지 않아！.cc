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
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        if (x == 1)
        {
            int a, t;
            cin >> a >> t;
            s.push({a, --t});
        }
        else
        {
            if(!s.empty())
                s.top().second--;
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
