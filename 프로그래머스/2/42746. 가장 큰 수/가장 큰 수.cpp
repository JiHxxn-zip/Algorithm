#include <iostream>
#include <string>
#include "algorithm"

using namespace std;

string solution(vector<int> numbers) 
{
     // str으로 형변환해서 vec에 담아줌
    vector<string> vec_str;

    vec_str.reserve(numbers.size());

    for (size_t i = 0; i < numbers.size(); i++)
        vec_str.push_back(to_string(numbers[i]));

    // sort에서 컴퍼레이터 함수를 만들어서 정렬 시도
    // 조건은 a+b > b+a 일 경우만 정렬하도록
    sort(vec_str.begin(), vec_str.end(),
    [](const string& a, const string& b) -> bool
    {
        return a + b > b + a;
    });

    string answer = "";

    for (string str : vec_str)
        answer += str;
    // 0인 예외처리
    if (answer[0] == '0' || answer.empty())
        answer = "0";

    return answer;
}