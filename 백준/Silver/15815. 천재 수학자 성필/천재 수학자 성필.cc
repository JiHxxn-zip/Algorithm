using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include <limits>
#include <cctype> 
#include <iomanip>

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;

    stack<ll> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))
            st.push(s[i] - '0');
        else
        {
            ll op2 = st.top();
            st.pop();
            ll op1 = st.top();
            st.pop();

            if (s[i] == '+')
                st.push(op2 + op1);
            else if (s[i] == '-')
                st.push(op1 - op2);
            else if (s[i] == '*')
                st.push(op1 * op2);
            else if (s[i] == '/')
                st.push(op1 / op2);
        }
    }

    cout << st.top();
    return 0;
}
