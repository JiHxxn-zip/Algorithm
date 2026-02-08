using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <climits> // INT_MAX

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int N;
    ll C, W;          // C: 자르는 비용, W: 단위 길이당 판매 가격
    cin >> N >> C >> W;

    vector<ll> tree(N);
    ll maxLen = 0;

    for (int i = 0; i < N; i++) 
    {
        cin >> tree[i];
        maxLen = max(maxLen, tree[i]);
    }

    ll answer = 0;

    // 막대 길이 L을 1부터 최대 길이까지 전부 시도
    for (ll L = 1; L <= maxLen; L++) {
        ll totalProfit = 0;

        for (ll t : tree) 
        {
            ll cnt = t / L;        // 만들 수 있는 막대 개수
            if (cnt == 0) 
                continue;

            // 자르는 횟수
            ll cuts = (t % L == 0) ? cnt - 1 : cnt;

            // 이익 계산
            ll profit = cnt * L * W - cuts * C;

            // 손해면 사용 안 함
            if (profit > 0)
                totalProfit += profit;
        }

        answer = max(answer, totalProfit);
    }

    cout << answer;
	return 0;
}