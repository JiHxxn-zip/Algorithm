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
    
    priority_queue<int, vector<int>, greater<int>> pq;

    int mx{};

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        pq.push(a);

        mx = max(mx, a);
    }

    int answer{};

    while (!pq.empty())
    {
        int cur = pq.top();
        pq.pop();

        int cnt{1};
        while (!pq.empty() && cur == pq.top())
        {
            pq.pop();
            cnt++;
        }

        answer += min(cnt, 2);
    }

    cout << answer;

    return 0;
}

