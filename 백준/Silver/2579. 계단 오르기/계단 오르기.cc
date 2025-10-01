#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int s[305], d[305];


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    int tot = 0;

    for (int i = 1; i <= n; i++) 
    {
        cin >> s[i];
        tot += s[i];
    }

    if (n == 1) 
    {
        cout << s[1];
        return 0;
    }
    else if (n == 2) 
    {
        cout << s[1] + s[2];
        return 0;
    }

    // 초기 셋팅
    d[1] = s[1];
    d[2] = s[2];
    d[3] = s[3];

    // 4부터 시작
    // 점화식 : 연속 3칸 제한 때문에 i에 오려면 i-2나 i-3에서 올 수 있음
    for (int i = 4; i <= n; i++) 
        d[i] = min(d[i - 2], d[i - 3]) + s[i];

    // 꼭대기 1, 2칸 전의 값 중 작은 값을 total 점수에서 빼준 값이 정답
    cout << tot - min(d[n - 1], d[n - 2]);

    return 0;
}