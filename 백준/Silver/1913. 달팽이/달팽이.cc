#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <climits> // INT_MAX

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, f;
    cin >> n >> f;

    vector<vector<int>> vec(n, vector<int>(n));

    int dir{};      // 방향
    int len{ 1 };   // 이동 칸 수
    int num{ 1 };   // 현재 숫자
    int r = n / 2;  // 시작 좌표
    int c = n / 2;

    int dr[4] = { -1, 0 ,1, 0 }; // 상 우 하 좌
    int dc[4] = { 0, 1, 0, -1 }; 

    int ans_r{}, ans_c{};
   
    while (num <= n*n)
    {
        for (int i = 0; i < 2; i++) // 같은 길이는 두 번
        {
            for (int j = 0; j < len; j++)
            {
                if (num > n * n)
                    break;

                if (num == f)
                {
                    ans_r = r;
                    ans_c = c;
                }

                vec[r][c] = num++;
                
                r += dr[dir];
                c += dc[dir];
            }
            dir = (dir + 1) % 4;
        }
        len++;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << vec[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << ans_r+1 << ' ' << ans_c+1;

    return 0;
}
