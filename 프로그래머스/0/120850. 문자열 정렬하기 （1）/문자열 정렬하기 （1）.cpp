#include <string>
#include <vector>
#include <algorithm>


using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer;
    for(int i=0;i<my_string.size();i++){
    	// my_string[i]가 정수인지 확인한다.
        if(isdigit(my_string[i]))
        	//answer에 요소를 추가한다(int로 변환하여 ( my_string의 i인덱스부터 + 1개 인덱스까지 ))
            answer.push_back(stoi(my_string.substr(i,1)));
    }
    // 오름차순으로 정렬한다
    sort(answer.begin(),answer.end());
    return answer;
}