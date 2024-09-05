#include<iostream>
#include <deque>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    deque<pair<int, int>> dq;
    int iInput(0), iMove(0);

    cin >> iInput;
    for (int i = 0; i < iInput; ++i)
    {
        cin >> iMove;
        dq.push_back(make_pair(i+1, iMove));
    }

    while (!dq.empty())
    {
        // 현재 풍선의 번호를 출력하고 지운다
        // 지울 때 얼마 만큼의 위치로 이동할 지 받아 놓고 for문으로 iter의 위치를 이동 시킨다

        cout << dq.front().first << ' ';
        iMove = dq.front().second;
        dq.pop_front();
        
        if (dq.empty())
            break;

        if (0 < iMove) // 양수
        {
            for (int i = 0; i < iMove- 1; ++i)
            {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else           // 음수
        {
            for (int i = 0; i < (-1) * iMove; ++i)
            {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }

    return 0;
}
