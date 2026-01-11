using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <climits>
#include <cctype> 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> vec(n + 2);    // 1번부터 i번까지 Yes 수
    vec[1] = 1;

    for (int i = 2; i <= n + 1; i++)
    {
        int type, x, y;
        cin >> type >> x >> y;

        int yesCnt = vec[y] - vec[x - 1];   // x 이전부터해야 x부터 y까지 Yes의 수
        int len = y - x + 1;                // 몇개의 질문이 있나

        bool ok;
        if (type == 1)
            ok = (yesCnt == len);
        else
            ok = (yesCnt == 0);

        cout << (ok ? "Yes\n" : "No\n");

        vec[i] = vec[i - 1] + (ok ? 1 : 0); // 이전 인덱스 값에 현재 점수 누적
    }

    return 0;
}

// 누적합