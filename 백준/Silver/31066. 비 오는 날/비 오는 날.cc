using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n, m, k; // 시작 위치 학생 수, 우산 수, 함께 쓸 수 있는 수
        cin >> n >> m >> k;

        int cap = m * k;

        if (cap == 1 && n > 1) {
            cout << -1 << '\n';
            continue;
        }

        if (n <= cap) {
            cout << 1 << '\n';
            continue;
        }

        int count{};
        
        while (n >= 0)
        {
            // 가는 카운트
            count++;

            n -= cap;
            
            if (n <= 0)
                break;

            // 돌아오는 카운트
            count++;
            n += 1;
        }

        cout << count << '\n';
    }


    return 0;
}

/*
7 2 2
1. 최대로 우산을 씌워서 보냄 [최대 2명 + 우산 2개] = 4명 -> 7-4 = 3
2. 돌아올 때 우산을 최소한의 인원으로? 가져옴 -> 4명이 되고, 2/2 해서 딱맞음 편도 3번
*/