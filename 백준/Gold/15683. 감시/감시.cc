#include <iostream>
#include <vector>
#include <unordered_map>
#include "algorithm"
using namespace std;

// 필요 속성
// 1. CCTV (번호, 좌표) 2. dirrection(카메라들마다의 위치) 3. dx,dy 4. 출발 시점(CCTV vector) 5. board 6. Result 7. Location

struct CCTV
{
    int num;
    int x, y;
};

struct Location
{
    int x, y;
};

// 상우하좌
int dx[4]{ 0, 1, 0, -1 };
int dy[4]{ 1, 0, -1, 0 };

vector<vector<vector<int>>> directions
{
    {},
    {{0}, {1}, {2}, {3}},
    {{0, 2}, {1, 3}},
    {{0, 1}, {1, 2}, {2, 3}, {3, 0}},
    {{0, 1, 2}, {1, 2, 3}, {2, 3, 0}, {3, 0, 1}},
    {{0, 1, 2, 3}}
};

vector<CCTV> cameras;

int board[10][10];

int result;

int row, col;

int minArea = 64;

// 필요 기능
// 1. DFS 2. Count_Area 3. Return_Location
void DFS(int Depth);
int Count_Area();
vector<Location> Return_Location(int depth, CCTV cam);

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> row >> col;

    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cin >> board[i][j];

            int camNum = board[i][j];

            if (camNum != 0 && camNum != 6)
            {
                CCTV cam{ camNum, j, i };
                cameras.push_back(cam);
            }
        }
    }

    DFS(0);

    cout << minArea;

    return 0;
}

void DFS(int Depth)
{
    // 현재 깊이와 카메라의 수를 비교해서 같으면 예외처리 시작
    if (Depth == cameras.size())
    {
        int curArea = Count_Area();

        minArea = min(minArea, curArea);
        return;
    }

    // 현재 카메라(깊이(인덱스)로 순서를 가져옴)
    CCTV curCam = cameras[Depth];

    // DFS 백트래킹 본문
    for (size_t i = 0; i < directions[curCam.num].size(); i++)
    {
        // 방문
        vector<Location> save = Return_Location(i, curCam);
        DFS(Depth + 1);

        // 방문 해제
        for (Location lo : save)
            board[lo.y][lo.x] = 0;
    }
}
int Count_Area()
{
    int area{};

    for (size_t i = 0; i < row; i++)
        for (size_t j = 0; j < col; j++)
            if (board[i][j] == 0)
                ++area;

    return area;
}
vector<Location> Return_Location(int depth, CCTV cam)
{
    vector<Location> re_Location;

    for (auto d : directions[cam.num][depth])
    {
        int nx = cam.x;
        int ny = cam.y;
    
        while (true)
        {
            nx += dx[d];
            ny += dy[d];

            if (nx < 0 || nx >= col || ny < 0 || ny >= row)
                break;
            if (board[ny][nx] == 6)
                break;

            if (board[ny][nx] == 0)
            {
                board[ny][nx] = -1;
                Location l{ nx, ny };
                re_Location.push_back(l);
            }



        }
    }

    return re_Location;
}