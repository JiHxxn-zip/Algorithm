using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <unordered_map>
#include <climits> // INT_MAX

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    deque<int> deq(n);
    for (int i = 0; i < n; i++)
    {
        cin >> deq[i];
    }

    sort(deq.begin(), deq.end());

    int result{};
    int prev{};
    bool isChack{ false };
    while (!deq.empty())
    {
        if (deq.size() == n) // 첫 번 쨰는 그냥 저장
        {
            prev = deq.back();
            deq.pop_back();
            result += prev;
            continue;
        }

        if (!isChack)
        {
            int r =  deq.front() - prev;
            if (r > 0)
                result += deq.front() - prev;

            prev = deq.front();
            deq.pop_front();
        }
        else
        {
            result += deq.back() - prev;
            prev = deq.back();
            deq.pop_back();
        }
        isChack = !isChack;
    }

    cout << result;
    return 0;
}

// i번째 공연자는 실력을 max(0, i - i1)
// 가장 먼저 공연하는 병사는 그대로 발휘
// 양 옆으로 가장 큰 것 배치 -> 그다음 가장 작은거 그다음 큰거

// 6 1 3 4 2 5 -> 6 0 2 1 0 3 : 12
// 6 1 5 2 4 3 -> 6 0 4 0 2 0 : 12

// deque로 했을 때 첫 번째값 저장
// 두번째부터 프론트에서 이전 값 뺴고, 다음에 이전값에서 백 빼야돼