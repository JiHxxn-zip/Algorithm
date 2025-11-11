using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

vector<int> vec[1001];
int deg[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    while (m--)
    {
        int num;
        cin >> num;

        vector<int> oder(num);

        for (int i = 0; i < num; i++)
            cin >> oder[i];
    
        for (int i = 0; i < num-1; i++)
        {
            vec[oder[i]].push_back(oder[i + 1]);
            deg[oder[i + 1]]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (deg[i] == 0)
            q.push(i);


    vector<int> oder;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        oder.push_back(cur);

        for (auto nx : vec[cur])
        {
            deg[nx]--;

            if (deg[nx] == 0)
                q.push(nx);
        }
    }

    if (oder.size() == n)
        for (auto a : oder)
            cout << a << '\n';
    else
        cout << 0;

    return 0;
}

// 방향 그래프
// degree 저장
// 0이 될 때 가지 돌리고, 0 이면 answer vector에 저장