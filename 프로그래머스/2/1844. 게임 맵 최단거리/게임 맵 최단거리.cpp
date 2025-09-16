#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include "algorithm"
using namespace std;

int board[502][502] = {};
bool vis[502][502] = {};
int bist[502][502] = {};
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int solution(vector<vector<int> > maps)
{
 int n = 0;
 n = maps[0].size();
 int m = 0;
 m =  maps.size();

 // board 셋팅
 for (size_t i = 0; i < maps.size(); i++)
 {
     int j = 0;
     for (auto p : maps[i])
     {
         board[i][j] = p;
         ++j;
     }
 }

 //
 queue<pair<int, int>> q;
 
 // 첫 위치
 vis[0][0] = 1;
 bist[0][0] = 1;
 q.push({ 0, 0 });

 int count{ 0 };

 while (!q.empty())
 {
     pair<int, int> cur = q.front();
     q.pop();

     for (int i = 0; i < 4; i++)
     {
         // 상하 좌우
         int nx = cur.second + dx[i];
         int ny = cur.first + dy[i];

         // 그리드 밖을 나갔거나, 가려는 지점이 0보다 작을 때 continue
         if (nx < 0 || nx >= n || ny < 0 || ny >= m)
             continue;

         // 이미 방문한 곳이거나 갈 수 없는 위치(1이 아니면) continue
         if (vis[ny][nx] || board[ny][nx] != 1)
             continue;

         vis[ny][nx] = 1;
         bist[ny][nx] = bist[cur.first][cur.second] + 1;
         q.push({ ny, nx});
     }

 }

    return bist[m - 1][n - 1] == 0 ? -1 : bist[m - 1][n - 1];
}