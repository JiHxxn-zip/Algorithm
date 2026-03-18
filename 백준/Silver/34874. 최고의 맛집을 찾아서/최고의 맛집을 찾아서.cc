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

    // 친구 n명, 식당 m개
    int n, m;
    cin >> n >> m;

    vector<vector<int>> vec(n, vector<int>(m));
    vector<int> maxVec(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> vec[i][j];
            maxVec[i] = max(maxVec[i], vec[i][j]);
        }
    }

    
    for (int i = 0; i < m; i++)
    {
        int count{};
        
        for (int j = 0; j < n; j++)
        {
            if (vec[j][i] < maxVec[j])
                count++;
        }

        cout << count << ' ';
    }



    return 0;
}