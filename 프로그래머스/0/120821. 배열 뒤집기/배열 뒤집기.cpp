#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> list) {
    vector<int> answer;
    
    for(int i = list.size()-1; i >= 0; i--){
       answer.push_back(list[i]); 
    }
    
    return answer;
}