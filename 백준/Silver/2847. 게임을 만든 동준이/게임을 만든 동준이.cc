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

    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.push(x);
    }

    int count{};
    while (!s.empty())
    {
        int cur = s.top();
        s.pop();

        if (!s.empty() && cur <= s.top())
        {
            int temp = s.top() - cur + 1;
            count += temp;
            s.top() -= temp;
        }
    }

    cout << count;
    return 0;
}
