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

    vector<pair<int, int>> scedule;
    scedule.reserve(n);

    int first{}, last{};
    for (int i = 0; i < n; i++)
    {
        cin >> first >> last;
        scedule.push_back({ last, first }); // 끝나는 시간을 first로 배치(sort 편하게 하려고) 
    }

    sort(scedule.begin(), scedule.end());

    int temp{}, count{};
    for (int i = 0; i < n; i++)
    {
        if (temp > scedule[i].second)
            continue;

        temp = scedule[i].first;
        count++;
    }

    cout << count;

    return 0;
}

// pair로 값을 저장하는데, 이 때 끝나는 시간으로 정렬을 해줌.
// ex. [0, 6], [1, 4]가 있다면 [1, 4]가 앞에 오도록
// 그리고 for문을 돌면서 현재 temp가 시작 시간보다 작으면 tmep를 끝나는 시간으로 갱신
