#include <iostream>
#include <string>
#include <unordered_map>
#include "algorithm"
using namespace std;

using namespace std;

int solution(vector<int> citations) {
     int answer = 0;

 // 첫 루프는 1~size 만큼돌고
 // 두 번째 루프는 배열안에 원소의 수가 i보다 큰 경우를 카운트 해야함. 그때 ㄱ
 sort(citations.begin(), citations.end());

 for (size_t i = 0; i < citations.size(); i++)
 {
     int count = 0;
     for (size_t j = 0; j < citations.size(); j++)
     {
         if (i + 1 <= citations[j])
             ++count;
     }
     if (i + 1 <= count)
         answer = i + 1;
 }

 return answer;
}