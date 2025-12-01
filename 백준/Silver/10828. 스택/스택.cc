using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    stack<int> s;

    while (n--)
    {
        string a;
        cin >> a;

        if (a == "push")
        {
            string num;
            cin >> num;
            s.push(stoi(num));

        }
        else if (a == "pop")
        {
            int output = s.empty() ? -1 : s.top();
            cout << output << '\n';

            if(!s.empty())
                s.pop();
        }
        else if (a == "size")
            cout << s.size() << '\n';
        else if (a == "empty")
            cout << s.empty() << '\n';
        else if(a=="top")
        {
            int output = s.empty() ? -1 : s.top();
            cout << output << '\n';
        }

    }
    return 0;
}