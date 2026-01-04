using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <climits>
#include <cctype> 

int N;
long long K;
vector<long long> A;
vector<int> memo; // -1: 미계산, 0: 불가능, 1: 가능

bool CanPass(int cur, int next) 
{
    long long dist = next - cur;                // j - i
    long long diff = llabs(A[cur] - A[next]);   // | Ai - Aj |
    long long need = dist * (1 + diff);         // (j - i) × (1 + | Ai - Aj |)
    return need <= K;
}

bool DP(int cur) 
{
    if (cur == N - 1)   // 마지막 돌다리에 닿았는지
        return true;

    int& m = memo[cur]; // 이미 값을 저장한 상태 (초기값 -1이 아닌) + 캐시에 바로 쓰려고
    if (m != -1) 
        return m;

    for (int next = cur + 1; next < N; ++next) 
    {
        if (!CanPass(cur, next)) // 조건 검사 - (j - i) × (1 + | Ai - Aj |)
            continue;

        if (DP(next)) // next에서 출발해서 마지막까지 가능한지
        {
            m = 1;// 현재 인덱스는 갈 수 있음
            return true;
        }
    }

    m = 0;  // cur에서 가능한 모든 next를 실패
    return false;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    A.resize(N);
    for (int i = 0; i < N; i++) 
        cin >> A[i];

    memo.assign(N, -1);

    cout << (DP(0) ? "YES" : "NO") << "\n";
    return 0;
}

/*(j - i) ×(1 + | Ai - Aj | )
1 - 0 x 1+ (4-1)= 4

dp?
돌은 인덱스가 증가하는 방향으로만 점프 가능
j-i는 거리
(1 + | Ai - Aj |)는 항상 1보다 같거나 크다
*/