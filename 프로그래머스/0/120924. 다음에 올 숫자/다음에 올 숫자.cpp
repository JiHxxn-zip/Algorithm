#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    int answer = 0;
    if (common[1] - common[0] != common[2] - common[1]){ // 1번 경우
        return common[common.size()-1] * (common[1] / common[0]);
    }
    else{
        if((common[0] < 0 && common[1] > 0) || (common[0] > 0 && common[1]<0)){ // 2-2번 경우
            return common[common.size()-1] * (common[1] / common[0]);
        }
        else if(common[0] == 0 && common[1]== 0){ // 3번 경우
            return common[common.size()-1] * (common[1] / common[0]);
        }
        else // 2-1번 경우
            return common[common.size()-1] + (common[1] - common[0]);
    }
    return answer;
}