using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <climits>

int board[102][102];

int dx[4]{ 0, 0, -1, 1 };
int dy[4]{ 1, -1, 0, 0 };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        for (int i = x; i < x + 10; i++)
        {
            for (int j = y; j < y + 10; j++)
            {
                board[i][j] = 1;
            }
        }
    }

    int result{};

    // 전수 검사 2중 for문
    for (int i = 0; i < 102; i++)
    {
        for (int j = 0; j < 102; j++)
        {
            if (board[i][j] == 1)
            {
                for (int d = 0; d < 4; d++)
                {
                    int ni = i + dx[d];
                    int nj = j + dy[d];
                    if (board[ni][nj] == 0)
                        result++;
                }
            }
           
        }
    }

    cout << result;
    
    return 0;
}

// 색종이 -> BFS 문제 ㅇ미ㅏㅓ링

// 0,0 부터 주어진 가장 큰 x,y를 바탕으로 
// 흠 외각선이니까 전수 검사를 하면서 외각선 수를 계산