#include <iostream>
#include <vector>
using namespace std;

// DFS 함수 : n, computers, 현재 위치
void DFS(int n, vector<vector<int>> computers, int cur);
bool vis[201];

int solution(int n, vector<vector<int>> computers) 
{
    int answer = 0;

    // 전수 검사를 위해 n 만큼 DFS 작동
    for (size_t i = 0; i < n; i++)
    {
        // 방문하지 않은 컴퓨터일 경우 DFS 작동
        if (!vis[i])
        {
            DFS(n, computers, i);
            ++answer;
        }
    }

    return answer;
}

void DFS(int n, vector<vector<int>> computers, int cur)
{
    vis[cur] = true;

    // 
    for (size_t i = 0; i < n; i++)
    {
        // 현재 루프의 컴퓨터가 방문하지 않았고, 현재 함수 내부의 컴퓨터는 방문을 한 상태일 경우
        if (!vis[i] && computers[cur][i] == 1)
        {
            DFS(n, computers, i);
        }
    }
}