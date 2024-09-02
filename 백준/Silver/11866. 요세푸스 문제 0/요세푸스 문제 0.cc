#include<iostream>
#include "queue"
using namespace std;

int main()
{
    queue<int> q;
    int iSize(0), iTarget(0);
    cin >> iSize >> iTarget;

    for (int i = 0; i < iSize; ++i)
        q.push(i+1);

    cout << '<';
    while (!q.empty())
    {
        for (int i = 0; i < iTarget; ++i)
        {
            if (i != iTarget-1)
            {
                int iTemp = q.front();
                q.push(iTemp);
            }
            else
            {
                cout << q.front();
            }
            q.pop();
        }

        if(!q.empty())
            cout << ", ";
    }
    cout << '>';
    return 0;
}
