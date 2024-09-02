#include<iostream>
#include "queue"
using namespace std;

int main()
{
    queue<int> q;
    int iInput(0);
    cin >> iInput;

    for (int i = 0; i < iInput; ++i)
        q.push(i+1);

    while (q.size() != 1)
    {
        q.pop();
        int iTemp = q.front();
        q.pop();
        q.push(iTemp);
    }
    cout << q.front();
    return 0;
}
