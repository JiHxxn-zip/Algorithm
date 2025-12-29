using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>
#include <unordered_set>
#include <set>

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
   
    unordered_set<string> seen;
    vector<set<char>> slots(n);
    vector<int> charPos(26, -1);

    bool ok{ true };

    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;

        // 문자열 중복 검사 -> 같은 문자가 있으면 조건에 불합
        if (!seen.insert(s).second)
            ok = false;

        // 실패했어도 주어진 입력은 끝까지 해야 함.
        if (!ok)
            continue;

        // 각 자리별 문자 처리
        for (int j = 0; j < n; j++)
        {
            char c = s[j]; 
            int idx = c - 'A';

            // 처음 보는 알파벳이면 이 자리에 고정
            if (charPos[idx] == -1)
                charPos[idx] = j;
            else if (charPos[idx] != j) // 이미 다른 자리에 나온 적 있으면 불가능
            {
                ok = false;
                break;
            }

            // j번 째 자리에서 가능한 문자로 추가
            slots[j].insert(c);
        }
    }

    // 조합 개수 확인
    if (ok)
    {
        long long total = 1;
        for (int i = 0; i < n; i++)
            total *= slots[i].size();

        if (total != m)
            ok = false;
    }

    if (!ok)
    {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++)
    {
        // set은 자동 정렬
        for (char c : slots[i])
            cout << c;

        cout << '\n';
    }

    return 0;
}
