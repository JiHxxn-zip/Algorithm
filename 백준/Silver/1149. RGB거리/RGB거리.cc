#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int board[1001][3];
int real[1001][3];


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n{};
    cin >> n;

    for (size_t i = 0; i < n; i++)
        cin >> board[i][0] >> board[i][1] >> board[i][2];

    if (n == 1)
        cout << board[0][0];
    else if (n == 2)
        cout << board[0][0] + board[0][1];

    real[0][0] = board[0][0];
    real[0][1] = board[0][1];
    real[0][2] = board[0][2];

    for (size_t i = 1; i < n; i++)
    {
        real[i][0] = min(real[i - 1][1], real[i - 1][2]) + board[i][0];
        real[i][1] = min(real[i - 1][0], real[i - 1][2]) + board[i][1];
        real[i][2] = min(real[i - 1][0], real[i - 1][1]) + board[i][2];
    }

    cout << *min_element(real[n-1], real[n-1]+3);

    return 0;
}