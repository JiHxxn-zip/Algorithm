#include <string>
#include <vector>

using namespace std;

long long solution(string numbers) {
    long long answer = 0;
    
    vector<string> Find_str = { "zero", "one", "two", "three", "four", "five",
        "six", "seven", "eight", "nine"};
    
    for(int i = 0; i < 10; i++){
        if(numbers.find(Find_str[i]) == string::npos) continue;
        while(numbers.find(Find_str[i]) != string::npos)
            numbers.replace(numbers.find(Find_str[i]), Find_str[i].size(), to_string(i));
    }
    answer = stoll(numbers);
    return answer;
}