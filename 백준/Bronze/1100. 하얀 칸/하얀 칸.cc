#include <iostream>
using namespace std;

int main()
{
    char map[9][9];
    cin.tie(0);
    cout.tie(0);
    int cnt = 0;
    for(int i = 1; i <= 8; i++)
    {
        for(int j = 1; j <= 8; j++)
        {
            cin >> map[i][j];
            if(i % 2 == 1) //홀수 줄일 때는 홀수 칸이 흰색
            { 
                if(j % 2 == 1 && map[i][j] == 'F') 
                    cnt++; 
            }
            else // 짝수 줄일 때는 짝수 칸이 흰색
            { 
                if(j % 2 == 0 && map[i][j] == 'F') 
                    cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}