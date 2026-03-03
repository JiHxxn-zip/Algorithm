using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
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

    int A, B;
    cin >> A >> B;

    vector<pair<int, int>> vec(n);
    set<pair<int, int>> set;
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i].first >> vec[i].second;
        set.insert(vec[i]);
    }

    int count{};

    for (int i = 0; i < n; i++)
    {
        int x = vec[i].first;
        int y = vec[i].second;

        if (set.find({ x + A, y }) != set.end() &&
            set.find({ x, y + B }) != set.end() &&
            set.find({ x + A, y + B }) != set.end())
        {
            count++;
        }
    }

    cout << count;
    return 0;
}
