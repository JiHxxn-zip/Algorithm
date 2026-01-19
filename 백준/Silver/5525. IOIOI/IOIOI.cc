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
	ios::sync_with_stdio(0);
	cout.tie(0);

    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    int result = 0;
    int cnt = 0;

    for (int i = 1; i < m - 1; i++) 
    {
        if (s[i - 1] == 'I' && s[i] == 'O' && s[i + 1] == 'I') 
        {
            cnt++;
            if (cnt == n) 
            {
                result++;
                cnt--; // 겹치는 패턴 처리
            }
            i++; // 다음 비교는 i+2부터
        }
        else 
            cnt = 0;
    }

    cout << result;
	return 0;
}