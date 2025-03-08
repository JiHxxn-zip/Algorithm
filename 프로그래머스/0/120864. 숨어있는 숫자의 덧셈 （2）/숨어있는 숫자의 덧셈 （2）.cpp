#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    for(auto& v : my_string)
    {
        if(!isdigit(v))
        {
            v = ' ';
        }
    }

    stringstream ss;
    ss.str(my_string);

    int tmp = 0;
    while(ss)
    {
        answer += tmp;
        ss >> tmp;
    }

    return answer;
}