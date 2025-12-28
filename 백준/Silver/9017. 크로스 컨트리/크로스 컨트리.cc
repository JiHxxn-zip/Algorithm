using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;


    while (t--)
    {
        int n;
        cin >> n;

        unordered_map<int, vector<int>> map_vec;
        vector<int> arr(n + 1); // i번째 도착한 팀 번호 저장

        for (int i = 1; i <= n; i++)
        {
            int team;
            cin >> team;
            arr[i] = team;
            map_vec[team].push_back(i);
        }

        // 6인 이상 팀 체크
        unordered_map<int, bool> valid;
        for (auto& p : map_vec)
            if ((int)p.second.size() >= 6)
                valid[p.first] = true;

        unordered_map<int, int> picked;
        unordered_map<int, int> sum4;
        unordered_map<int, int> fifth;

        int score{};
        for (int i = 1; i <= n; i++)
        {
            int team = arr[i];
            if (!valid[team])
                continue;

            score++;
            int p = ++picked[team];

            if (p <= 4)
                sum4[team] += score;
            else if (p == 5)
                fifth[team] = score;
        }

        int winner = -1;
        int bestSum = INT_MAX;
        int bestFifth = INT_MAX;

        for (auto& p : map_vec)
        {
            int team = p.first;
            if (!valid[team])
                continue;

            if (sum4[team] < bestSum || (sum4[team] == bestSum && fifth[team] < bestFifth))
            {
                bestSum = sum4[team];
                bestFifth = fifth[team];
                winner = team;
            }
        }

        cout << winner << '\n';
    }


    return 0;
}
