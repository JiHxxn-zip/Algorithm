using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <limits>
#include <cctype> 
#include <iomanip>

typedef long long ll;
deque<char> dq;
int bCount{}, wCount{};

void Normalize(int rotCount)
{
    if (rotCount == 1)
    {
        while (!dq.empty() && dq.front() == 'b')
        {
            dq.pop_front();
            bCount--;
        }
    }
    else if (rotCount == 3)
    {
        while (!dq.empty() && dq.back() == 'b')
        {
            dq.pop_back();
            bCount--;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;

    int rotCount{};
    for (int i = 0; i < q; i++)
    {
        string c;
        cin >> c;

        if (c == "push")
        {
            char x;
            cin >> x;

            if (x == 'b') bCount++;
            else wCount++;

            dq.push_back(x);   // queue의 back
            Normalize(rotCount);
        }
        else if (c == "rotate")
        {
            char x;
            cin >> x;

            if (x == 'l') rotCount = (rotCount + 3) % 4;
            else rotCount = (rotCount + 1) % 4;

            Normalize(rotCount);
        }
        else if (c == "count")
        {
            char x;
            cin >> x;

            if (x == 'b') cout << bCount << '\n';
            else cout << wCount << '\n';
        }
        else if (c == "pop")
        {
            if (!dq.empty())
            {
                if (dq.front() == 'b') bCount--;
                else wCount--;

                dq.pop_front();   // queue의 front는 항상 front
                Normalize(rotCount);
            }
        }
    }

    return 0;
}