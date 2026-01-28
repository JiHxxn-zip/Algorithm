using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>
#include <cctype> 
#include <iomanip>
#include <set>

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<string> vec(n);
    for (int i = 0; i < n; i++) 
        cin >> vec[i];

    set<char> ans;

    for (char x = 'A'; x <= 'Z'; x++) 
    {
        int cnt = 0;
        int onlyIdx = -1;

        for (int i = 0; i < n; i++) 
        {
            if (vec[i][0] == x) 
            {
                cnt++;
                onlyIdx = i;
            }
        }
        if (cnt == 0) 
            continue;

        if (cnt >= 2) 
        {
            // x로 시작하는 유전자가 2개 이상이면 모든 유전자와 조합 가능
            for (int i = 0; i < n; i++) 
                ans.insert(max(x, vec[i][1]));
        }
        else 
        {
            // cnt == 1이면 자기 자신(그 하나)만 제외하고 조합
            for (int i = 0; i < n; i++) 
            {
                if (i == onlyIdx) 
                    continue;
                ans.insert(max(x, vec[i][1]));
            }
        }
    }

    cout << ans.size() << "\n";
    for (char c : ans) 
        cout << c << ' ';
    return 0;
}