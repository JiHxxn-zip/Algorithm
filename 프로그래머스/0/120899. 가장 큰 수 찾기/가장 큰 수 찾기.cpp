#include <string>
#include <vector>
 
using namespace std;
 
vector<int> solution(vector<int> array) {
    vector<int> answer;
    
    int max_num = 0;
    int max_index = 0;
    
    // 배열을 순회하며 가장 큰 값과 인덱스를 찾는다.
    for(int i = 0; i < array.size(); i++)
    {
        // 현재 저장한 값보다 보고 있는 값이 크다면 
        // 큰 값과 인덱스를 갱신해준다.
        if (max_num < array[i])
        {
            max_num = array[i];
            max_index = i;
        }
    }
    
    answer.push_back(max_num);
    answer.push_back(max_index);
    
    return answer;
}
