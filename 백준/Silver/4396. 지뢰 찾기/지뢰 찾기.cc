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

int dx[8]{0, 0, -1, 1, -1, 1, -1, 1};
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
    
    vector<string> resultBoard(n);
    for (int i = 0; i < n; i++)
        cin >> resultBoard[i];

    vector<string> result(n, string(n, '.'));
    bool exploded{ false };
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (resultBoard[i][j] == 'x' && board[i][j] == '*')
                exploded = true;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (resultBoard[i][j] == 'x' && board[i][j] == '*') 
                exploded = true;

            // 하나씩 비교
            char cur = resultBoard[i][j];
            int count{};

            if (cur == 'x')
            {
                for (int k = 0; k < 8; k++)
                {
                    int nx = j + dx[k];
                    int ny = i + dy[k];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                        continue;
                    if (board[ny][nx] == '*')
                        count++;
                }
                result[i][j] = count + '0';
            }
            else
                result[i][j] = resultBoard[i][j];
            
        }
    }
    
    if (exploded)
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
    return 0;
}