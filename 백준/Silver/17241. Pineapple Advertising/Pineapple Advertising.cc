using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
#include <cctype> 
#include <iomanip>

typedef long long ll;

vector<int> house[200001];
int visit[200001] = { 0 };

int delivery(int start) 
{
    if (visit[start] == -2) 
        return 0;   // 이미 이 집에서 직접 광고함

    int cnt = 0;

    if (visit[start] == 0) 
        cnt++;                  // 아직 광고 못 받았던 집이면 자기 자신 포함
    
    visit[start] = -2;          // 이제 이 집은 직접 광고한 집으로 처리

    for (int i = 0; i < house[start].size(); i++) 
    {
        int a = house[start][i];
        if (visit[a] == 0) 
        {
            cnt++;
            visit[a] = -1;      // 광고 받음(직접 광고한 건 아님)
        }
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    // 집, 길, 피자
    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        house[a].push_back(b);
        house[b].push_back(a);
    }

    for (int i = 0; i < q; i++)
    {
        int temp;
        cin >> temp;
        cout << delivery(temp) << '\n';
    }
    return 0;
}