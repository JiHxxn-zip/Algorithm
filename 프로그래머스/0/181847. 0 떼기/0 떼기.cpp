#include <string>

using namespace std;

int find(string str) {
    for(int i = 0; i < str.size(); ++i) {
        if(str[i] != '0') return i;
    }
}

string solution(string n_str) {
    string answer = "";
    int n = find(n_str);
    
    for(int i = n; i < n_str.size(); ++i) {
        answer += n_str[i];
    }
    return answer;
}