using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits>
#include <cctype> 
#include <iomanip>

typedef long long ll;

enum class EPos
{
    right, down, left, up
};

EPos& operator++(EPos& pos)
{
    pos = static_cast<EPos>(static_cast<int>(pos) + 1);
    return pos;
}
EPos& operator--(EPos& pos)
{
    pos = static_cast<EPos>(static_cast<int>(pos) - 1);
    return pos;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, t;
    cin >> n >> t;

    if (n == 0)
    {
        cout << t << ' ' << n;
        return 0;
    }

    pair<int, int> curPos{};
    EPos curEPos = EPos::right;
    int prvPower{}, add{};
    while (n--)
    {
        int ti;
        cin >> ti;
        string si;
        cin >> si;

        if (prvPower == 0 && add == 0)
            add += ti;
        else
            add += (ti - prvPower);

        if (curEPos == EPos::right)
            curPos.first += abs(prvPower - ti);
        else if (curEPos == EPos::down)
            curPos.second -= abs(prvPower - ti);
        else if(curEPos == EPos::left)
            curPos.first -= abs(prvPower - ti);
        else if (curEPos == EPos::up)
            curPos.second += abs(prvPower - ti);

        if (si == "right")
        {
            if (curEPos == EPos::up)
                curEPos = EPos::right;
            else
                ++curEPos;
        }
        else if (si == "left")
        {
            if (curEPos == EPos::right)
                curEPos = EPos::up;
            else
                --curEPos;
        }

        prvPower = ti;
    }

    if (t > add)
    {
        if (curEPos == EPos::right)
            curPos.first += t - add;
        else if (curEPos == EPos::down)
            curPos.second -= t - add;
        else if (curEPos == EPos::left)
            curPos.first -= t - add;
        else if (curEPos == EPos::up)
            curPos.second += t - add;
    }

    cout << curPos.first << ' ' << curPos.second;

    return 0;
}