#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include "algorithm"
using namespace std;

// 필요 속성 : 보드, 방문 기록, 위치 카운터, 상하좌우
int board[502][502];
bool vis[502][502];
int dist[502][502];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

int solution(vector<vector<int> > maps)
{
    // 매 판 보드의 크기가 달라질 것이 때문에 행과 열을 저장해줄 변수
    int row = maps.size();
    int col = maps[0].size();

    // 주어진 mpas로 보드 셋팅
    for (size_t i = 0; i < maps.size(); i++)
    {
        for (size_t j = 0; j < maps[i].size(); j++)
            board[i][j] = maps[i][j];
    }
   
    // 순회를 돌 좌표를 저장해줄 q
    queue < pair<int, int>> q;

    // 시작 방문 지점 체크
    vis[0][0] = 1;
    dist[0][0] = 1;

    // q 시작 지점 삽입
    q.push({ 0,0 });

    // q의 순회를 도와줄 while
    while (!q.empty())
    {
        // q에서 원소를 뽑아줌 -> front, pop
        auto cur = q.front();
        q.pop();

        // 상하좌우 검수
        for (size_t i = 0; i < 4; i++)
        {
            // 다음 이동할 지점 셋팅
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            // 예외처리
            if (ny < 0 || ny >= row || nx < 0 || nx >= col) continue; // 벽 밖으로 못 나가게 셋팅
            if (vis[ny][nx] == 1 || board[ny][nx] == 0) continue; // 방문된 곳 or 갈 수 없는 곳(0) 셋팅

            // 방문 기록 및 q에 다음 지점 삽입
            vis[ny][nx] = 1;
            dist[ny][nx] = dist[cur.first][cur.second] + 1;

            q.push({ ny,nx });
        }

    }

    // 보드 끝(row,col)의 dist값이 0이면 -1 반환, 아니면 저장된 값 반환 
    return dist[row - 1][col - 1] == 0 ? -1 : dist[row - 1][col - 1];
}