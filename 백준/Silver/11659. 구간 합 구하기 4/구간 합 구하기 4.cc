#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n, m;
int board[100001];
int real[100001];


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    board[0] = 0;

    cin >> n >> m;
    
    for (size_t i = 1; i <= n; i++)
    {
        cin >> board[i];

        real[i] = board[i] + real[i - 1];
    }

    while (m--)
    {
        int i{}, j{};
        cin >> i >> j;

        cout << real[j] - real[i - 1] << '\n';
    }

    return 0;
}