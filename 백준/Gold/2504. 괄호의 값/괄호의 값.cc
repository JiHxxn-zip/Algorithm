#include <iostream>
#include "stack"
using namespace std;

int main()
{
    /*
    조건 1. 짝이 맞지 않으면 무조건 0 처리.
    조건 2. ‘()’ 인 괄호열의 값은 2이다.
    조건 3. ‘[]’ 인 괄호열의 값은 3이다.
    조건 4. ‘(X)’ 의 괄호값은 2×값(X) 으로 계산된다.
    조건 5. ‘[X]’ 의 괄호값은 3×값(X) 으로 계산된다.
    (()[[]])([])    = 22 + 6 = 28
        (()[[]])    = 안부터 계산하면 (2+3x3)x2 = 11 
        ([])        = 3 x 2
    */

    stack<char> stack{};
    int sum = 0;
    int temp = 1;
    int answer = 0;

    string str{};
    cin >> str;

    for (size_t i = 0; i < str.size(); i++)
    {
        // 지금 차례와 다음 차레를 순회하되, 맨 끝까지 가봐야함. 맨 끝이랑 맞으면 pop
        // 앞으로 쭉 가되 연속적으로 닫+열이 있다면 멈춤. 
        // ex. [()()()][]() = 3x(2+2+2)+3+2

        if (str[i] == '(')
        {
            stack.push('(');
            temp *= 2;
        }
        else if (str[i] == '[')
        {
            stack.push('[');
            temp *= 3;
        }
        else if (str[i] == ')')
        {
            if (stack.empty() || stack.top() != '(')
            {
                answer = 0;
                break;
            }
            else if (str[i - 1] == '(')
            {
                answer += temp;
            }

            temp /= 2;
            stack.pop();
        }
        else if (str[i] == ']')
        {
            if (stack.empty() || stack.top() != '[')
            {
                answer = 0;
                break;
            }
            else if (str[i - 1] == '[')
            {
                answer += temp;
            }

            temp /= 3;
            stack.pop();
        }
    }

    if (!stack.empty())
        answer = 0;

    cout << answer;
}

/*
(()[[]])([])
*/