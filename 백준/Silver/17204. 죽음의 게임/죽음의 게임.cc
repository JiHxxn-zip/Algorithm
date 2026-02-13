using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <limits>
#include <cctype> 
#include <iomanip>

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k; // 참여하는 사람 수, 보성 번호
    cin >> n >> k;

    vector<int> vec(n);
    for (int i = 0; i < n; i++) 
        cin >> vec[i];

    int cur = 0;

    // 시작이 0이므로, k==0이면 지목을 0번만에 이미 도달
    if (cur == k) 
    {
        cout << 0;
        return 0;
    }

    for (int i = 1; i <= n; i++) 
    {
        cur = vec[cur];        // 한 번 지목
        if (cur == k) 
        {
            cout << i;     // 지목 횟수
            return 0;
        }
    }

    cout << -1;
    return 0;
}