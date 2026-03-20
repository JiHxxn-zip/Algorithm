using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
#include <cctype> 
#include <iomanip>

typedef long long ll;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> vec(n, vector<int>(m, 0));
    vector<int> maxSco(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> vec[i][j];
            maxSco[i] = max(maxSco[i], vec[i][j]);
        }
    }

    vector<int> count(m);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(vec[j][i] < maxSco[j])
                count[i]++;
        }
        cout << count[i] << ' ';
    }

    return 0;
}