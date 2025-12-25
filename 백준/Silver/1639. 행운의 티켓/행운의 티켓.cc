using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int n = static_cast<int>(s.size());

    // 누적합
    vector<int> pref(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int d = s[i] - '0'; // 아스키코드 0 == 48, 1 == 49
        pref[i + 1] = pref[i] + d;
    }

    // 람다 함수 객체 생성
    auto rangeSum = [&](int l, int r)
    {
        return pref[r + 1] - pref[l];
    };

    int answer{};

    for (int len = (n/2) * 2; len >= 2; len -= 2) // (n / 2) * 2 = n보다 작거나 같은 가장 큰 짝수
    {
        bool found = false;
        for (int l = 0; l + len <= n; l++) // l을 왼쪽부터 하나씩 옮김
        {
            int mid = l + len / 2;                      // 반으로 나눔
            int leftSum = rangeSum(l, mid - 1);         // 왼쪽 합 계산
            int righitSum = rangeSum(mid, l + len - 1); // 오른쪽 합 계산

            if (leftSum == righitSum)
            {
                answer = len;
                found = true;
                break;
            }
        }
        if (found)
            break;
    }

    cout << answer << '\n';

    return 0;
}
