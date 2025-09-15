#include <iostream>
#include <string>
#include <unordered_map>
#include "algorithm"
using namespace std;

bool solution(vector<string> phone_book) {
     unordered_map<string, int> map;

 // Hash map 생성
 for (size_t i = 0; i < phone_book.size(); i++)
     map.insert({ phone_book[i], 1 });


 for (size_t i = 0; i < phone_book.size(); i++)
 {
     // 사이즈는 -1로 자신을 찾지 못하게 1개 빼서 검색해줌
     for (size_t j = 0; j < phone_book[i].size() - 1; j++)
     {
         // 접두사 추출(0~j+1)
         string a = phone_book[i].substr(0, j + 1);

         // 추출한 값을 map에 key로 넣었을 때 value 값이 있으면 끝.
         if (map[a])
             return false;
     }
 }

 return true;
}