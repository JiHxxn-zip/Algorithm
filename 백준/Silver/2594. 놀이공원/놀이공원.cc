using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <limits>
#include <cctype> 
#include <iomanip>

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    
    vector<pair<string, string>> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i].first >> vec[i].second;

    sort(vec.begin(), vec.end());

    int mx{};
    int startWork = 600;
    int endWork = 22 * 60;
    bool first = true;
    int prevEndTime{};
    for (int i = 0; i < n; i++)
    {
        string stHour = vec[i].first.substr(0, 2);
        string stMinute = vec[i].first.substr(2, 2);

        string enHour = vec[i].second.substr(0, 2);
        string enMinute = vec[i].second.substr(2, 2);

        int stH = (stoi(stHour) * 60) + stoi(stMinute);
        int enH = (stoi(enHour) * 60) + stoi(enMinute);

        stH -= 10;
        enH += 10;

        // 쉬는 시간부터 사이 시작시간
        if (first)
        {
            mx = max(mx, stH - startWork);
            prevEndTime = enH;

            first = false;
        }
        else
        {
            if (stH > prevEndTime)
            {
                mx = max(mx, stH - prevEndTime);
                prevEndTime = enH;
            }
            else
            {
                prevEndTime = max(prevEndTime, enH);
            }
        }
    }

    mx = max(mx, endWork - prevEndTime);
    cout << mx;

    return 0;
}

// 하루 일과 시작 10to10
// 놀이기구 작동 시작 10분전 부터 멈추고 10분 후 까지는 쉴 수 없음
