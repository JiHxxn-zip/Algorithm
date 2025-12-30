using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;       // 현재 나타나있는 과녁 n, 다음에 나타날 과녁 m
    cin >> n >> m;

    vector<pair<ll, ll>> visible(n);
    for (int i = 0; i < n; i++)
        cin >> visible[i].first >> visible[i].second;

    vector<pair<ll, ll>> up(m);
    for (int i = 0; i < m; i++)
        cin >> up[i].first >> up[i].second;

    ll current_X{}, current_Y{};
    ll total{};


    for (int i = 0; i < m; i++)
    {
        // 현재 커서에서 가장 먼 과녁 찾아야함
        ll curBest = -1;
        int bestIndex{};

        for (int j = 0; j < visible.size(); j++)
        {
            ll dx = current_X - visible[j].first;
            ll dy = current_Y - visible[j].second;
            ll d = dx * dx + dy * dy;  // 거리 제곱            
            
            if (d > curBest)
            {
                curBest = d;
                bestIndex = j;
            }
        }

        // 점수 누적
        total += curBest;
        current_X = visible[bestIndex].first;
        current_Y = visible[bestIndex].second;

        // 과녁 제거
        visible.erase(visible.begin() + bestIndex);

        // 다음 과녁 추가
        visible.push_back(up[i]);
    }

    cout << total << '\n';

    return 0;
}
