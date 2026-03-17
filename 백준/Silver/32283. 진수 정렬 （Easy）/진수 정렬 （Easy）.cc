using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <limits>
#include <iomanip> // 소숫점 제한

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    if (r == 0 || r == n) return 1;
    if (r > n / 2) r = n - r;
    long long ans = 1;
    for (int i = 1; i <= r; i++) {
        ans = ans * (n - i + 1) / i;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    string S;
    cin >> S;

    int k = count(S.begin(), S.end(), '1'); // 1의 개수 세기

    // 1의 개수 적은 애들 전부 더하기
    long long answer = 0;
    for (int i = 0; i < k; i++) 
        answer += nCr(N, i);

    // reverse
    string reversedS = S;
    reverse(reversedS.begin(), reversedS.end());

    for (int i = 0; i < (1 << N); i++) 
    {
        // 모든 숫자 i에 대해 1의 개수 확인
        int cnt = 0;
        for (int j = 0; j < N; j++) 
            if (i & (1 << j)) 
                cnt++;

        if (cnt == k) 
        {
            // i를 이진수 문자열로 변환 (N자리 유지)
            string current = "";
            for (int j = N - 1; j >= 0; j--) 
                current += (i & (1 << j)) ? '1' : '0';

            // 이 문자열을 뒤집은 형태 생성
            string revCurrent = current;
            reverse(revCurrent.begin(), revCurrent.end());

            // 뒤집은 문자열이 입력받은 S를 뒤집은 것보다 사전순으로 앞서면 answer 증가
            if (revCurrent < reversedS) 
                answer++;
        }
    }

    cout << answer;
    return 0;
}