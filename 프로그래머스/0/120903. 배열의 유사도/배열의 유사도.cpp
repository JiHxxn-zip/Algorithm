#include <string>
#include <vector>
 
using namespace std;
 
int solution(vector<string> s1, vector<string> s2) {
    int answer = 0;
    
    // s1의 모든 원소를 순회
    for(int i = 0; i < s1.size(); i++)
    {
        // s2의 모든 원소를 순회
        for (int j = 0; j < s2.size(); j++)
        {
            // 모든 원소를 일일이 다 비교한다. (브루트 포스)
            if(s1[i] == s2[j])
            {
                answer++;
            }
        }
    }
    
    return answer;
}
