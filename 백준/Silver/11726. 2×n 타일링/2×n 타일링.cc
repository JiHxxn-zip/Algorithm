#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int board[10005];
int mode = 10007;


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n{};
    cin >> n;

    board[0] = 1;
    board[1] = 2;

    for (size_t i = 2; i < n; i++)
        board[i] = (board[i-1] + board[i-2]) % mode;

    cout << board[n - 1];

    return 0;
}