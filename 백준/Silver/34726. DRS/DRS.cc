using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cctype> 
#include <iomanip>
#include <unordered_map>
#include <queue>

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, T;
    cin >> n >> T;

    vector<pair<int, string>> cars;
    cars.reserve(n);

    ll behind_mod = 0; // 누적 뒤처짐 mod T

    for (int i = 0; i < n; i++)
    {
        string name;
        ll ti;
        cin >> name >> ti;

        if (i == 0) 
            behind_mod = 0;
        else 
            behind_mod = (behind_mod + (ti % T)) % T;

        int pos = (T - (int)behind_mod) % T; // 트랙 상 절대 위치(진행방향 기준)
        cars.push_back({ pos, name });
    }

    sort(cars.begin(), cars.end()); // pos 오름차순

    vector<string> answer;
    answer.reserve(n);

    for (int i = 0; i < n; i++)
    {
        int j = (i + 1) % n;
        int dist = (cars[j].first - cars[i].first + T) % T; // i에서 j까지 앞으로 가는 거리

        if (1 <= dist && dist <= 1000)
            answer.push_back(cars[i].second);
    }

    if (answer.empty())
    {
        cout << -1 << "\n";
        return 0;
    }

    sort(answer.begin(), answer.end());
    for (int i = 0; i < answer.size(); i++) 
    {
        if (i) 
            cout << ' ';
        cout << answer[i];
    }
    cout << "\n";
    return 0;
}
