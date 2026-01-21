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

    string s;
    cin >> s;

    for (int len = 1; len <= 6; len++) 
    {
        if (len > s.size()) 
            break;

        long long cur = stoll(s.substr(0, len));
        long long start = cur;

        string built = "";
        while (built.size() < s.size()) 
        {
            built += to_string(cur);
            cur++;
        }

        if (built == s) 
        {
            cout << start << " " << cur - 1;
            return 0;
        }
    }
	return 0;
}

// 가로로만 가능 다른 수가 나오면 카운트 증가
// 


// 자료구조, 그래프 탐색, 그리디/DP/백트래킹, 
// LIS, 그래프, 구현, 이분탐색, 문자열, 비트마스크, 누적합