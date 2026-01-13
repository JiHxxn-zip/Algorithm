using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <deque>
#include <climits> // INT_MAX

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    
    deque<int> deq(n+1);
    for (int i = 1; i <= n; i++)
        cin >> deq[i];

    sort(deq.begin(), deq.end());

    int result{};
    if (n % 2 == 0) // 짝수는 그룹으로 2개씩 ㅏ나눠
    {
        for (int i = 0; i < n / 2; i++)
        {
            result += deq.back() * 2;
            deq.pop_back();
            deq.pop_front();
        }
    }
    else            // 홀수는 그룹으로 나누고 나머지 하나는 그냥 더해
    {
        for (int i = 0; i < n / 2; i++)
        {
            result += deq.back() * 2;
            deq.pop_back();
            deq.pop_front();
        }
        result += deq.back();
    }
    
    cout << result;


    return 0;
}

// 개별로 나눌 수 있는지 확인
// n이 짝수이고 2개보다 클 때 2개씩 나누는데, 이 때 크고 작은 걸로 나눔
