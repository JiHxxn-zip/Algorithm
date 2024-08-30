#include<iostream>
#include "stack"
using namespace std;

int main()
{
    stack<char> stack;
    int iNum(0);
    string str("\0");

    cin >> iNum;
    for (int i = 0; i < iNum; ++i)
    {
        cin >> str;
        for (int j = 0; j < str.length(); ++j)
        {
            if (str[j] == '(')
            {
                if (!stack.empty())
                {
                    if (stack.top() == ')')
                        stack.pop();
                    else
                        stack.push('(');
                }
                else
                    stack.push('(');
            }
            else if (str[j] == ')')
            {
                if (!stack.empty())
                {
                    if (stack.top() == '(')
                        stack.pop();
                    else
                        stack.push(')');
                }
                else
                {
                    stack.push(')');
                    break;
                }
            }
        }

        if (stack.empty())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
            while (!stack.empty())
                stack.pop();
        }

    }

    return 0;
}
