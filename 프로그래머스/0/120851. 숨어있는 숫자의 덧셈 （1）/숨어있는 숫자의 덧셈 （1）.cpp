#include <string>
#include <vector>
 
using namespace std;
 
int solution(string my_string) {
    int answer = 0;
    
    for(int i = 0; i < my_string.length(); i++)
    {
        if (my_string[i] >= '0' && my_string[i] <= '9')
        {
            // 아스키 코드에서 '0'은 숫자 0이 아니므로.
            answer += my_string[i] - '0';
        }
    }
    return answer;
}
