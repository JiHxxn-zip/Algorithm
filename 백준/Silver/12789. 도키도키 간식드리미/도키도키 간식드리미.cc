#include<iostream>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack<int> s;
    int iLoop(0), iInput(0), iCurrentNum(1);
    cin >> iLoop;

    for (int i = 0; i < iLoop; ++i)
    {
        cin >> iInput;

        if (iInput != iCurrentNum)
            s.push(iInput);
        else
            ++iCurrentNum;

        while (!s.empty() && s.top() == iCurrentNum)
        {
            s.pop();
            ++iCurrentNum;
        }
    }

    if(s.empty())
        cout << "Nice";
    else
        cout << "Sad";

    return 0;
}
