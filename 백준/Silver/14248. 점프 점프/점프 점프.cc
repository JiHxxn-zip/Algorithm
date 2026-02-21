using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
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

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];

    int s;
    cin >> s;

    queue<int> q;
    q.push(s - 1);

    vector<bool> vis(n, false);
    int answer{};

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (vis[cur])
            continue;

        vis[cur] = true;
        answer++;

        int nextFront = cur + vec[cur];
        int nextBack = cur - vec[cur];

        if (nextFront < n && !vis[nextFront])
            q.push(nextFront);

        if (nextBack >= 0 && !vis[nextBack])
            q.push(nextBack);
    }
        
    cout << answer;

    return 0;
}
