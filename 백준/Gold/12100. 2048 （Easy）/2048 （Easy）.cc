#include <iostream>
#include <vector>
#include "algorithm"
using namespace std;

int n;

int board1[21][21]; // 원본
int board2[21][21]; // 회전 시켜 값을 뽑아줄 사본

void Tilt(int dir); // 게임 핵심인 값을 계산해주는 함수
void RoTate();      // Board를 90도로 돌려줄 함수

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
            cin >> board1[i][j];
    }
    
    // 최대값을 저장해줄 변수
    int mx{};
    
    // 4의5승번 돌려줌(4방향, 5번 기회)
    for (size_t i = 0; i < 1024; i++)
    {
        // 원본 복사
        for (size_t j = 0; j < n; j++)
        {
            for (size_t k = 0; k < n; k++)
                board2[j][k] = board1[j][k];
        }

        int brute = i;

        // 5번의 기회 에서 4방향 전수 검사
        for (size_t j = 0; j < 5; j++)
        {
            int dir = brute % 4;

            // 다음 이동 방향 저장
            brute /= 4; 

            Tilt(dir);
        }

        // 최대 값 추출
        for (size_t j = 0; j < n; j++)
        {
            for (size_t k = 0; k  < n; k ++)
                mx = max(mx, board2[j][k]);
        }
    }

    cout << mx;

    return 0;
}

void Tilt(int dir)
{
    // 해당 검사에 회전 시켜야 할 수 만큼 돌려주고 시작
    while (dir--)
    {
        RoTate();
    }

    // 값을 계산해주기 위해 2중 for문을 사용해도 되지만
    // 임의 접근 방식을 잘 활용하면 1중 for문으로도 구현 가능해 시간 복잡도를 줄일 수 있음
    for (size_t i = 0; i < n; i++)
    {
        int temp[21]{};   // 해당 열의 계산된 값을 저장해줄 변수
        int idx{};        // 위 배열의 인덱스를 관리해줄 변수

        for (size_t j = 0; j < n; j++)
        {
            if (board2[i][j] == 0)
                continue;

            if (temp[idx] == 0)                     // 위에서 board의 예외처리를 넘겨왔기 때문에 0이면 무조건 현재 board값을 가져옴
                temp[idx] = board2[i][j];
            else if (temp[idx] == board2[i][j])     // 만약 이번 턴의 값이 똑같다면 합쳐주어야 하기 때문에 해당 index에 값을 2배로 하고
                temp[idx++] *= 2;                   // 이번 인덱스는 더 이상 채울 수 없기 때문에 후위 증감 연산으로 값을 늘려줌
            else
                temp[++idx] = board2[i][j];         // 위 조건들이 모두 아니면 바로 전위 증감 연산을 사용해 다음 칸에 이번 board 값을 채워줌

        }

        // 열의 값 옮겨주기
        for (size_t j = 0; j < n; j++)
        {
            board2[i][j] = temp[j];
        }
    }
}

void RoTate()
{
    // Board를 돌려주기 위한 임시 변수
    int temp[21][21] = {};

    // 돌려줄 보드 복사
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
            temp[i][j] = board2[i][j];
    }

    // 90도 회전
    for (size_t i = 0; i < n; i++)
    {
        // 90도 회전 공식 - 행과 열을 바꾼다.
        for (size_t j = 0; j < n; j++)
            board2[i][j] = temp[n - 1 - j][i];
    }
}


// 보드판이 있는 숫자들을 4방향으로 회전시켜 합쳐진 가장 큰 값을 추출하는 문제
// 5번의 기회가 있으니 전수 검사를 하여 큰값을 도출해야됨.
// 4방향에 4번의 기회이니 4의5승(1024)번 브루트포스를 진행해야됨.
// 상하좌우로 값을 계산하는 함수보다 
    // 왼쪽 계산하는 함수를 만들고, 보드판 자체를 돌려 4방향 값을 뽑아주는 게 효율적.
