#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n, m;
vector<int> vec;

int lower_idx(int target);
int upper_idx(int target);

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    vec.reserve(n);

    int x;
    for (int i = 0; i < n; i++) 
    {
        cin >> x;
        vec.push_back(x); 
    }
    sort(vec.begin(), vec.end());

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;

        cout << upper_idx(t) - lower_idx(t) << ' ';
    }
    return 0;
}

int lower_idx(int target)
{
    int st = 0;
    int en = n;

    while (st < en)
    {
        int mid = (en + st) / 2;

        if (vec[mid] >= target)
            en = mid;
        else
            st = mid + 1;
    }

    return st;
}
int upper_idx(int target)
{
    int st = 0;
    int en = n;

    while (st < en)
    {
        int mid = (en + st) / 2;

        if (vec[mid] > target)
            en = mid;
        else
            st = mid + 1;
    }

    return st;
}