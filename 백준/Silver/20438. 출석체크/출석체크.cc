using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k, q, m;
    cin >> n >> k >> q >> m;

    int maxId = n + 2; // 3번부터 N + 2번까지 

    vector<bool> sleep(maxId + 1, false);   // 자는 사람
    vector<bool> attend(maxId +1, false);   // 출결 처리

    // 자는 사람 적립
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        sleep[x] = true;
    }

    // 출석코드 보내는 학생 Q
    vector<int> senders(q);
    for (int i = 0; i < q; i++)
        cin >> senders[i];

    // 출석코드 전파
    for (int x : senders)
    {
        if (sleep[x])
            continue;

        for (int i = x; i <= maxId; i += x)
        {
            if (!sleep[i])
                attend[i] = true;
        }
    }

    // 결석자 누적합 만들기
    vector<int> pref(maxId + 1, 0);
    for (int i = 1; i <= maxId; i++)
    {
        pref[i] = pref[i - 1];
        if (i >= 3) // 3 ~ n+2
            if (!attend[i])     // 출석 false면 결석 카운트
                pref[i]++;
    }

    // 구간 처리
    while (m--)
    {
        int s, e;
        cin >> s >> e;
        cout << (pref[e] - pref[s - 1]) << '\n';
    }

    return 0;
}
// 3, 5, 6, 9, 10, 12

// 누적합