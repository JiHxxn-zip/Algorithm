#include <string>
#include <vector>
 
using namespace std;
 
string solution(string rsp) {
    string answer = "";
    
    for(int i = 0; i < rsp.length(); i++)
    {
        // 가위라면 바위
        if (rsp[i] == '2')
        {
            answer += '0';
        }
        // 바위라면 보
        else if (rsp[i] == '0')
        {
            answer += '5';
        }
        // 보라면 가위
        else {
            answer += '2';
        }
    }
    
    return answer;
}