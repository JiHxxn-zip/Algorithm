#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
       string answer = "";
   unordered_map<string, int> map;

   for (size_t i = 0; i < participant.size(); i++)
   {
       // map에서 find 함수를 통해 현재
   }

   for (string player : participant)
   {
       // map에서 find 함수를 통해 현재 player를 찾을 수 없다면 새로 저장
       if (map.end() == map.find(player))
           map.insert({ player,1 });
       else // 찾았다면 동명이인이 있다는 뜻이고 한명 더 추가
           map[player]++;
   }

   // 도착점에 들어온 player들을 map에 저장된 선수에서 빼준다.
   for (string player : completion)
       map[player]--;

   // map에 저장된 player 중 숫자가 0보다 크면 그 선수가 범인
   for (string player : participant)
   {
       if (map[player] > 0)
       {
           answer = player;
           break;
       }
   }

   return answer;
}