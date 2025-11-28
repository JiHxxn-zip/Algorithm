using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> nova(n);
    for (int i = 0; i < n; i++)
        cin >> nova[i];

    sort(nova.begin(), nova.end());

    vector<int> origin(m);
    for (int i = 0; i < m; i++)
        cin >> origin[i];

    sort(origin.begin(), origin.end());

    int novaCount{}, originCount{};

    int novaT{};
    for (int t : nova)
    {
        if (t >= novaT)
        {
            novaCount++;
            novaT = t + 100;
        }
    }

    int originT{};
    for (int t : origin)
    {
        if (t >= originT)
        {
            originCount++;
            originT = t + 360;
        }
    }

    
    cout << novaCount << ' ' << originCount;

    return 0;
}

// 노바 재사용 시간 100초
// 오리진 재사용 시간 360초

// 면역 시간 90초
