#include<iostream>
#include "stack"
#include "string"
using namespace std;

int main()
{
    stack<char> stack;
    string str("\0");
    bool bEscape(false);
    
    while (true)
    {
        getline(cin, str);
        if (str == ".")
            break;

        for (int i = 0; i < str.length(); ++i)
        {
            if (str[i] == '(' || str[i] == '[')
            {
                stack.push(str[i]);
                bEscape = true;
            }
            else if (str[i] == ')' || str[i] == ']')
            {
                if (stack.empty())
                {
                    stack.push(str[i]);
                    break;
                }

                if (stack.top() == '(' && str[i] == ')')
                    stack.pop();
                else if (stack.top() == '[' && str[i] == ']')
                    stack.pop();
                else
                {
                    stack.push(str[i]);
                    bEscape = true;
                }
            }
        }

        if (stack.empty() || !bEscape)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
            while (!stack.empty())
                stack.pop();
        }
    }

    return 0;
}
