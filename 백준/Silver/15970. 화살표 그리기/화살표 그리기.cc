using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>
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

    vector<pair<int, int>> vec(n);
    for (int i = 0; i < n; i++)
    {
        int f, s;
        cin >> f >> s;

        vec[i] = { f,s };
    }

    sort(vec.begin(), vec.end());

    int result{};
    for (int i = 0; i < n; i++)
    {
        int curMin = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;

            if (vec[i].second == vec[j].second)
                curMin = abs(min(curMin, vec[j].first - vec[i].first));
        }
        result += curMin;
    }

    cout << result;
    return 0;
}
 

// 가까운 점
// first가 좌표 second가 가장 가까워야함

// 자료구조, 그래프 탐색, 그리디/DP/백트래킹, 
// LIS, 그래프, 구현, 이분탐색, 문자열, 비트마스크, 누적합
