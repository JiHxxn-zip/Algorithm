using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cctype> 
#include <iomanip>
#include <unordered_map>
#include <set>

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    int need = (9 * M + 9) / 10; // ceil(9M/10)

    unordered_map<int, int> cnt;
    cnt.reserve(N * 2);

    multiset<int> freqBag;

    auto add = [&](int x) {
        int old = cnt[x];
        if (old > 0) {
            auto it = freqBag.find(old);
            if (it != freqBag.end()) freqBag.erase(it);
        }
        int now = ++cnt[x];
        freqBag.insert(now);
        };

    auto removeOne = [&](int x) 
        {
        int old = cnt[x]; // old >= 1 보장
        auto it = freqBag.find(old);
        if (it != freqBag.end()) freqBag.erase(it);

        int now = --cnt[x];
        if (now == 0) {
            cnt.erase(x);
        }
        else {
            freqBag.insert(now);
        }
        };

    // 초기 윈도우
    for (int i = 0; i < M; i++) add(A[i]);

    if (!freqBag.empty() && *freqBag.rbegin() >= need) 
    {
        cout << "YES\n";
        return 0;
    }

    // 슬라이딩
    for (int i = M; i < N; i++) 
    {
        removeOne(A[i - M]);
        add(A[i]);

        if (!freqBag.empty() && *freqBag.rbegin() >= need) 
        {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}
 