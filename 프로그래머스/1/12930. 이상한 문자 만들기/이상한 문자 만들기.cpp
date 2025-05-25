#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<string> vec;
    
    int size = s.length();
    int idx = 0;
    
    for (int i = 0 ; i < size ; i++) {
        if (s[i] == ' ') {
            idx = 0;
        }
        else if (idx % 2 == 0) {
            s[i] = toupper(s[i]);
            idx += 1;
        }
        else if (idx % 2 != 0) {
            s[i] = tolower(s[i]);
            idx += 1;
        }
    }
    
    answer = s;
    
    return answer;
}