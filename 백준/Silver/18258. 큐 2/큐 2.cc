#include<iostream>
#include "queue"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    queue<int> queue;
    string str("\0"), command("\0");
    int iLoop(0), iOutput(0);

    cin >> iLoop;

    for (int i = 0; i < iLoop; ++i)
    {
        cin >> str;

        if (str =="push")
        {
            cin >> iOutput;
            queue.push(iOutput);
        }
        else if (str == "pop")
        {
            iOutput = queue.empty() ? -1 : queue.front();
            cout << iOutput << '\n';

            if (!queue.empty())
                queue.pop();
        }
        else if (str == "size")
            cout << queue.size() << '\n';
        else if (str == "empty")
        {
            iOutput = queue.empty() ? 1 : 0;
            cout << iOutput << '\n';
        }
        else if (str == "front")
        {
            iOutput = queue.empty() ? -1 : queue.front();
            cout << iOutput << '\n';
        }
        else if (str == "back")
        {
            iOutput = queue.empty() ? -1 : queue.back();
            cout << iOutput << '\n';
        }
    }

    return 0;
}
