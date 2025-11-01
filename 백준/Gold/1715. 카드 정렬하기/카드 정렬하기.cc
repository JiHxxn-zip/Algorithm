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

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;

    int num{};
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        pq.push(num);
    }

    int answer{};
    while (pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();

        answer += a + b;
        pq.push(a + b);
    }

    cout << answer;

    return 0;
}
