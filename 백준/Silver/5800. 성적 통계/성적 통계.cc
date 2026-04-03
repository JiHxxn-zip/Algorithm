using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits>
#include <cctype> 
#include <iomanip>

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k;
    cin >> k;

    int classNum{};
    while (k--)
    {
        int n;
        cin >> n;
        vector<int> vec(n);

        int mx{}, mn{numeric_limits<int>::max()};
        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
            mx = max(vec[i], mx);
            mn = min(vec[i], mn);
        }
        sort(vec.rbegin(), vec.rend());

        int mxGap{};
        for (int i = 1; i < n; i++)
        {
            mxGap = max(mxGap, abs(vec[i - 1] - vec[i]));
        }

        classNum++;
        cout << "Class " << classNum << '\n' <<
            "Max " << mx << ", " << "Min " << mn << ", " << "Largest gap " << mxGap << '\n';
    }
    return 0;
}