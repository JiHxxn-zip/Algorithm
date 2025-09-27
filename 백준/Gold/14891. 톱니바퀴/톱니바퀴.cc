#include <iostream>
#include <vector>
#include <deque>
#include "algorithm"
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<deque<char>> gears(4);  // 크기 4로 초기화
    string str_gear[4];

    for (size_t i = 0; i < 4; i++)
    {
        cin >> str_gear[i];
        for (char s : str_gear[i])
        {
            gears[i].push_back(s);
        }
    }

    int n;
    cin >> n;

    int gearNum, gearRot;
    int rots[4];
    bool isRots[4];

    for (size_t i = 0; i < n; i++)
    {
        cin >> gearNum >> gearRot;
        fill(begin(rots), end(rots), 0);

        rots[gearNum - 1] = gearRot;

        // 왼쪽 전파
        for (int j = gearNum - 1; j > 0; j--) 
        {
            if (gears[j][6] != gears[j - 1][2])
                rots[j - 1] = -rots[j];
            else
                break;
        }

        // 오른쪽 전파
        for (int j = gearNum - 1; j < 3; j++) 
        {
            if (gears[j][2] != gears[j + 1][6])
                rots[j + 1] = -rots[j];
            else
                break;
        }

        // 회전 적용
        for (int j = 0; j < 4; j++) 
        {
            if (rots[j] == 1) // 시계
            { 
                char back = gears[j].back();
                gears[j].pop_back();
                gears[j].push_front(back);
            }
            else if (rots[j] == -1) // 반시계
            { 
                char front = gears[j].front();
                gears[j].pop_front();
                gears[j].push_back(front);
            }
        }
    }
    
    int answer{};
    for (size_t i = 0; i < gears.size(); i++)
    {
        if (gears[i][0] == '1')
        {
            if (i == 0)
                answer += 1;
            else if (i == 1)
                answer += 2;
            else if (i == 2)
                answer += 4;
            else if (i == 3)
                answer += 8;
        }
        //if (gears[i][0] == '1')
        //answer += (1 << i);   
    }

    cout << answer;

    return 0;
}