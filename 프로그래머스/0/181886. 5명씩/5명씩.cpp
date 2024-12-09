#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> names) 
{
    vector<string> answer;

    // names 리스트가 비어있지 않은 동안 반복
    while (!names.empty()) 
    {
        // 한 그룹을 구성할 벡터
        vector<string> group;
        
        // 한 그룹에 최대 5명을 추가
        for (int i = 0; i < 5; ++i) 
        {
            // names가 비어있으면 반복 종료
            if (names.empty()) break;
            
            // names의 맨 앞에 있는 사람을 그룹에 추가하고 삭제
            group.push_back(names.front());
            names.erase(names.begin());
        }
        
        // 한 그룹의 맨 앞에 있는 사람을 answer에 추가
        if (!group.empty()) 
        {
            answer.push_back(group.front());
        }
    }

    return answer;
}