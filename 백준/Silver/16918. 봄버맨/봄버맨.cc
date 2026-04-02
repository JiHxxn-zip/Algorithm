using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits>
#include <cctype> 
#include <iomanip>

typedef long long ll;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

vector<string> Explode(vector<string> vec, int r, int c)
{
    vector<string> result(r, string(c, 'O'));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (vec[i][j] == 'O')
            {
                result[i][j] = '.';

                for (int k = 0; k < 4; k++)
                {
                    int ny = i + dy[k];
                    int nx = j + dx[k];

                    if (ny < 0 || ny >= r || nx < 0 || nx >= c)
                        continue;

                    result[ny][nx] = '.';
                }
            }
        }
    }

    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int r, c, n;
    cin >> r >> c >> n;

    vector<string> vec(r);
    for (int i = 0; i < r; i++)
        cin >> vec[i];

    if (n == 1)
    {
        for (int i = 0; i < r; i++)
            cout << vec[i] << '\n';
    }
    else if (n % 2 == 0)
    {
        for (int i = 0; i < r; i++)
            cout << string(c, 'O') << '\n';
    }
    else
    {
        vector<string> first = Explode(vec, r, c);
        vector<string> second = Explode(first, r, c);

        if (n % 4 == 3)
        {
            for (int i = 0; i < r; i++)
                cout << first[i] << '\n';
        }
        else
        {
            for (int i = 0; i < r; i++)
                cout << second[i] << '\n';
        }
    }

    return 0;
}