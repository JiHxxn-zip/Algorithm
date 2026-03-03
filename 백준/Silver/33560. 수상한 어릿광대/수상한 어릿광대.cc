using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
#include <cctype> 
#include <iomanip>

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int addTime{ 4 }, curTime{}, endTime{ 240 };
    int addPoint{ 1 }, curPoint{};
    vector<int> gamePoints;

    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;

        // 시간 초과 시 적립
        if (curTime > endTime)
        {
            gamePoints.push_back(curPoint);
            // 초기화
            curPoint = 0; curTime = 0; addTime = 4; addPoint = 1;
        }

        if (value == 1) // 게임 즉시 종료
        {
            gamePoints.push_back(curPoint);
            // 초기화
            curPoint = 0; curTime = 0; addTime = 4; addPoint = 1;
            continue;
        }

        switch (value)
        {
            case 2: // 얻는 점수가 1보다 크면 /2, 1이면 매 턴 시간 2씩 증가
                if (addPoint > 1)
                    addPoint /= 2;
                else if (addPoint == 1)
                    addTime += 2;
                break;

            case 4: // 이번 턴만 시간을 56 추가로 흐르게 만듦
                curTime += 56; // 4번은 즉시 curTime에 추가
                break;

            case 5: // 매 턴 흐르는 시간이 1보다 큰 경우 해당 값이 1 감소
                if (addTime > 1) 
                    addTime -= 1;
                break;

            case 6: // 얻는 점수가 32보다 작은 경우 2배
                if (addPoint < 32)
                    addPoint *= 2;
                break;
        }

        curPoint += addPoint;
        curTime += addTime;
    }

    vector<int> result(4);
    for (int x : gamePoints)
    {
        if (x >= 35 && x < 65)
            result[0]++;
        else if (x >= 65 && x < 95)
            result[1]++;
        else if (x >= 95 && x < 125)
            result[2]++;
        else if (x >= 125)
            result[3]++;
    }

    for (int i = 0; i < 4; i++)
        cout << result[i] << '\n';

    return 0;
}
