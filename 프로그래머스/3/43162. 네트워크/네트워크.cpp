#include <vector>

using namespace std;
int vis[201];

void DFS(int n, vector<vector<int>> computers, int cur)
{
    vis[cur] = true;
    
    for(int i = 0; i < n; ++i)
    {
        // 방문 안한 컴퓨터와 현재 컴퓨터가 1로 체크된 컴퓨터
        if(!vis[i] && computers[cur][i] == 1)
        {
            // 서로 묶어서 방문 체크되기 때문에 갯수 카운트 안됨
            DFS(n, computers, i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) 
{
    int answer = 0;
    
    // 컴퓨터마다 방문 체크
    for(int i = 0; i < n; ++i)
    {
        if(!vis[i])
        {
            DFS(n, computers, i);
            answer++;
        }
    }
    
    return answer;
}

// 벡터들의 인덱스들끼리 서로 맞닿아있다면 Count++