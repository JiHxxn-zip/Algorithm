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
    for (int i = 0; i < n*n; i++)
    {
        cin >> num;
        pq.push(num);

        if (pq.size() > n)
            pq.pop();
    }

    cout << pq.top();


    return 0;
}
