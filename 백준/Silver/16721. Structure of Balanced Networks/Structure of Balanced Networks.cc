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

    int n;
    cin >> n;
    vector<unsigned char> grp(n, 0);

    for (int j = 0; j < n; j++) 
    {
        char s;
        cin >> s;
        if (j == 0) 
            continue; 

        grp[j] = (s == '-') ? 1 : 0; // '+'면 0, '-'면 1
    }

    // 나머지 행은 그냥 버리기 (저장할 필요 없음)
    for (int i = 1; i < n; i++) 
    {
        for (int j = 0; j < n; j++)
        {
            char s;
            cin >> s;
        }
    }

    int m;
    cin >> m;
    while (m--) 
    {
        int b, c;
        cin >> b >> c;
        cout << (grp[b] == grp[c] ? '+' : '-') << "\n";
    }

    return 0;
}