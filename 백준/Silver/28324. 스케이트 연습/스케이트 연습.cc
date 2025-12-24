using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    int sum{}, cur{};
    for (int i = n; i >= 1; i--)
    {
        cur = min(cur+1, vec[i-1]);
        sum += cur;
    }

    cout << sum;
    return 0;
}

