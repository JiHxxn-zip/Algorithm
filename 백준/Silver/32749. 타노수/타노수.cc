using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <unordered_map>
#include <climits> // INT_MAX

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, t;
    cin >> n >> t;

    string x;
    cin >> x;

    vector<string> vec;

    long long nam = x.size();
    for (int i = 0; i < t; i++)
        nam /= 2;

    if (nam == 0)
    {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < x.size(); i+=nam)
        vec.push_back(x.substr(i, nam));

    string mx = "";
    for (auto& a : vec)
        mx = max(mx, a);

    cout << mx;

    return 0;
}