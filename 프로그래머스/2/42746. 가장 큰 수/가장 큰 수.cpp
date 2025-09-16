#include <iostream>
#include <string>
#include "algorithm"

using namespace std;

string solution(vector<int> numbers) {
     // vec<string> 안에 먼저 넣어줌
  vector<string> vec_str;
  vec_str.reserve(numbers.size());

  for (size_t i = 0; i < numbers.size(); i++)
      vec_str.push_back(to_string(numbers[i]));

  // 정렬을 해줄건데, 컴퍼레이터 함수를 만들어줄거임.
  sort(vec_str.begin(), vec_str.end(),
      [](const string& a, const string& b) -> bool
      {
          return a + b > b + a;
      });

  string answer = "";
  
  for (string str : vec_str)
      answer += str;

  if (answer.empty() || answer[0] == '0')
      answer = "0";

  return answer;
}