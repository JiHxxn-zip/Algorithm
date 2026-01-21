using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <climits> // INT_MAX

int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> vec(N, vector<int>(M));
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++) 
            cin >> vec[i][j];
    }

    int ans = 0;

    // 각 행마다 처리
    for (int i = 0; i < N; i++) 
    {
        int cnt1 = 0;
        int cnt2 = 0;
        int prev = 0;  // 이전 칸의 색

        for (int j = 0; j < M; j++) 
        {
            if (vec[i][j] == 0) 
            {
                // 0 만나면 지금까지 색 덩어리 처리
                if (cnt1 || cnt2) 
                    ans += min(cnt1, cnt2) + 1;
                
                cnt1 = 0;
                cnt2 = 0;
                prev = 0;
            }
            else if (vec[i][j] == 1) 
            {
                // 색 1 구간의 시작
                if (prev == 0 || prev == 2) cnt1++;
                prev = 1;
            }
            else 
            { 
                // arr[i][j] == 2
                if (prev == 0 || prev == 1) cnt2++;
                prev = 2;
            }
        }

        // 행 끝에서도 남아있다면 처리
        if (cnt1 || cnt2) 
            ans += min(cnt1, cnt2) + 1;
    }

    cout << ans << "\n";
    return 0;
}

// 가로로만 가능 다른 수가 나오면 카운트 증가