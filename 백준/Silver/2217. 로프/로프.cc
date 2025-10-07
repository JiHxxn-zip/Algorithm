#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n{};
    cin >> n;

    vector<int> w;
    w.reserve(n);

    int k;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        w.push_back(k);
    }

    sort(w.begin(), w.end());

    int answer{};
    for (int i = 0; i < n; i++)
        answer = max(answer, w[i] * (n - i));

    cout << answer;

    return 0;
}

// 로프의 힘을 균등하게 배분하려면 최소의 힘을 내는 로프를 시작으로 값을 비교해 가면 됨
