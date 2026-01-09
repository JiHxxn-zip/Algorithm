using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <climits>
#include <cctype> 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, int>> vec(k);
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;

        vec[i] = { a,b };
    }

    sort(vec.begin(), vec.end(), [](auto& a, auto& b)
    {
        return a.second < b.second;
    });

    priority_queue<int, vector<int>, greater<int>> pq;
    long long sum{};

    for (int i = 0; i < k; i++)
    {
        int v = vec[i].first;
        int c = vec[i].second;

        pq.push(v); // 선호도 누적
        sum += v;

        if (pq.size() > n) // n(열리는 기간)동안만 마실 거기 때문에 초과하면 빼준다.
        {
            sum -= pq.top();
            pq.pop();
        }

        if (pq.size() == n && sum >= m) // 열리는 기간, 선호도가 채워졌을 경우
        {
            cout << c;  // 정렬된 값에서 현재 값이 최소 도수 레벨
            return 0;
        }
    }

    cout << -1;

    return 0;
}
// 열리는 기간, 선호도 합, 맥주 종류
// 선호도, 도수 레벨
// 선호도 합을 채우면서 열리는 기간 동안 맥주를 모두 마실 수 있는 레벨 최솟값