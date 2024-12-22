#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

string solution(string my_string) {
    string answer = "";
    unordered_set<char> us;
    for(const auto v : my_string)
    {
        if(!us.count(v))
        {
            answer.push_back(v);
            us.insert(v);
        }
    }
    return answer;
}