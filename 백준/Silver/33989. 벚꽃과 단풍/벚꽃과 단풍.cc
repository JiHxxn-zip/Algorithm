using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <limits>
#include <cctype> 
#include <iomanip>
#include <unordered_map>

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    // prefixD[i] = s[0..i-1] 에서 'D' 개수
    vector<int> prefixD(n + 1, 0);
    for (int i = 0; i < n; ++i) 
        prefixD[i + 1] = prefixD[i] + (s[i] == 'D');

    // suffixB[i] = s[i..n-1] 에서 'B' 개수
    vector<int> suffixB(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) 
        suffixB[i] = suffixB[i + 1] + (s[i] == 'B');

    int ans = numeric_limits<int>::max();
    // 분기점 i: [0..i-1]은 B로, [i..n-1]은 D로 만든다고 생각
    for (int i = 0; i <= n; ++i)
        ans = min(ans, prefixD[i] + suffixB[i]);

    cout << ans << "\n";

    return 0;
}


