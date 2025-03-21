#include <string>
#include <vector>
#include <regex>

using namespace std;

string solution(string my_string) {
    string answer = "";
    answer = regex_replace(my_string, regex("[aeiou]+"), "");
    return answer;
}