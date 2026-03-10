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
    cout.tie(0);
    
    // 등장횟수 m 동방의 갯수 n
    int n, m;
    cin >> n >> m;

    vector<int> vec(n-1, 0);
    for (int i = 0; i < m; i++)
    {
        int st, en;
        cin >> st >> en;

        if (st > en)
            continue;

        for (int j = st-1; j <= en-2; j++)
        {
            vec[j] = 1;
        }
    }

    int count{}, prev{};
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == 0)
            count++;
    }

    cout << count+1;

    return 0;
}