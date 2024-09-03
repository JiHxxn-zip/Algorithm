#include<iostream>
#include <deque>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    deque<int> dq;

    int iLoop(0), iInput(0);
    cin >> iLoop;

    for (int i = 0; i < iLoop; ++i)
    {
        cin >> iInput;

        switch (iInput)
        {
            case 1:
                cin >> iInput;
                dq.push_front(iInput);
                break;

            case 2:
                cin >> iInput;
                dq.push_back(iInput);
                break;

            case 3:
                if (dq.empty())
                {
                    cout << "-1\n";
                }
                else
                {
                    cout << dq.front() << '\n';
                    dq.pop_front();
                }
                break;

            case 4:
                if (dq.empty())
                {
                    cout << "-1\n";
                }
                else
                {
                    cout << dq.back() << '\n';
                    dq.pop_back();
                }
                break;

            case 5:
                cout << dq.size() << '\n';
                break;

            case 6:
                cout << dq.empty() ? "1" : "0";
                cout << '\n';
                break;

            case 7:
                if (dq.empty())
                    cout << "-1\n";
                else
                    cout << dq.front() << '\n';
                break;

            case 8:
                if (dq.empty())
                    cout << "-1\n";
                else
                    cout << dq.back() << '\n';
                break;

            default:
                break;
        }
    }

    return 0;
}
