using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include <limits>
#include <cctype> 
#include <iomanip>

typedef long long ll;

int dx[8]{ 0, 0, -1, 1, -1, 1, -1, 1 };
int dy[8]{ 1, -1, 0, 0, 1, 1, -1, -1 };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<string> board(n);
    for (int i = 0; i < n; i++)
        cin >> board[i];

    vector<string> inputBoard(n);
    for (int i = 0; i < n; i++)
        cin >> inputBoard[i];

    bool isExplosion{ false };
    for (int i = 0; i < i; i++)
        for (int j = 0; j < n; j++)
            if (inputBoard[i][j] == 'x' && board[i][j] == '*')
                isExplosion = true;

    vector<string> result(n, string(n, '.'));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (inputBoard[i][j] == 'x' && board[i][j] == '*')
                isExplosion = true;

            if (inputBoard[i][j] == 'x')
            {
                int count{};
                for (int k = 0; k < 8; k++)
                {
                    int nx = dx[k] + j;
                    int ny = dy[k] + i;

                    if (nx >= n || nx < 0 || ny >= n || ny < 0)
                        continue;

                    if(board[ny][nx] == '*')
                        count++;
                }
                result[i][j] = count + '0';
            }
            else
                result[i][j] = inputBoard[i][j];
        }
    }

    if (isExplosion)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == '*')
                    result[i][j] = '*';
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << result[i] << '\n';
    }
}