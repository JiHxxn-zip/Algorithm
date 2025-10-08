#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    vector<int> vec(n);

    for (int i = 0; i < n; i++)
        cin >> vec[i];

    sort(vec.begin(), vec.end());

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        cout << binary_search(vec.begin(), vec.end(), t) << '\n';
    }

    return 0;
}