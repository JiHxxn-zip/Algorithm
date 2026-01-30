using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>
#include <cctype> 
#include <iomanip>
#include <deque>

typedef long long ll;
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
	
    vector<ll> vecA(n);
    vector<ll> vecB(n);

    for (int i = 0; i < n; i++)
        cin >> vecA[i];

    for (int i = 0; i < n; i++)
        cin >> vecB[i];

    // 이분탐색? -> 레라?
    for (int i = 0; i < n; i++)
    {
        //
        auto it = upper_bound(vecB.begin() + i, vecB.end(), vecA[i]);

        ll output = it - vecB.begin() - i;

        cout << output - 1 << ' ';
    }

    return 0;
}
 
// 잉크지수, 점토지수

// xi는 i번째 칸에 서서 롤러를 사용할 때 최대로 칠할 수 있는 칸의 개수
