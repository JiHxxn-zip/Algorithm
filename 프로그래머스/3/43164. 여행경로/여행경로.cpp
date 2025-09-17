#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "algorithm"
using namespace std;

// 답을 담는 그릇
vector<string> answer;

// 방문 기록
bool vis[512];

// 사용한 티겟 수
int usedTicket{};

bool DFS(vector<vector<string>> tickets, string cur)
{
    answer.push_back(cur);
    ++usedTicket;
    
    if (tickets.size()+1 == usedTicket)
        return true;

    for (size_t i = 0; i < tickets.size(); i++)
    {
        if (vis[i] == false && tickets[i][0] == cur)
        {
            vis[i] = true;
            
            bool t = DFS(tickets, tickets[i][1]);
            if (t == true) 
                return true;

            vis[i] = false;
        }
    }

    answer.pop_back();
    --usedTicket;
    return false;

}

vector<string> solution(vector<vector<string>> tickets) 
{
    // 정렬 한번해주고
    sort(tickets.begin(), tickets.end());

    DFS(tickets, "ICN");

    return answer;
}