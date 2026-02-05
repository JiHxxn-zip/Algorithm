using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cctype> 
#include <iomanip>
#include <unordered_map>
#include <stack>


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string besy;
    cin >> besy;

    // 큐로 2개를 쌓고 (( open 카운트 증가 바로 직전이 (였는지 true/false
    // 그다음 ))은 앞에 카운트가 있을 때 쌓고 없으면 쌓지않음

    bool isOpen{ false };
    bool isClose{ false };
    int openCount{};
    int result{};
    for (int i = 0; i < besy.size(); i++)
    {
        if (besy[i] == '(')
        {
            isClose = false;

            if (isOpen)
                openCount++;
            else
                isOpen = true;
        }
        else
        {
            isOpen = false;
            if (openCount > 0)
            {
                if (isClose)
                {
                    result+= openCount;
                    //openCount--;
                }
                else
                    isClose = true;
            }
        }
    }

    cout << result;

    return 0;
}
