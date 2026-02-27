using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
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

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> vec(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            vec[i][j] = 0;
   
    ll grass_count = 1LL * n * m;

    for (int i = 0; i < q; i++)
    {
        int op;
        cin >> op;

        if (op == 1)
        {
            int dy, dx, y, x;
            cin >> dy >> dx >> y >> x;
            --y; --x; // to 0-index

            while (0 <= y && y < n && 0 <= x && x < m && vec[y][x] == 0)
            {
                vec[y][x] = 1;
                grass_count--;

                y += dy;
                x += dx;
            }
            //cout << (vec[y][x] == 0 ? 0 : 1) << '\n';

        }
        else if (op == 2)
        {
            int y, x;
            cin >> y >> x;
            --y; --x; // to 0-index

            cout << (int)vec[y][x] << "\n";
        }
        else
            cout << grass_count << "\n";
    }
    
    
    return 0;
}
