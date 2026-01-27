using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>
#include <cctype> 
#include <iomanip>

typedef long long ll;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> limit(101), speed(101); 

    int pos{};
    // 도로 제한속도 펼치기
    for (int i = 0; i < n; i++) 
    {
        int len, v;
        cin >> len >> v;

        for (int k = 0; k < len; k++)
            limit[pos++] = v;
    }

    pos = 0;
    for (int i = 0; i < m; i++)
    {
        int len, v;
        cin >> len >> v;

        for (int j = 0; j < len; j++)
            speed[pos++] = v;
    }
    
    int answer{};
    for (int i = 0; i < 100; i++)
        answer = max(answer, speed[i] - limit[i]);

    cout << answer;

    return 0;
}