#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{ 
    bool answer = true;

 int pCount{ 0 };
 int yCount{ 0 };

 for (size_t i = 0; i < s.size(); i++)
 {
     if (s[i] == 'p' || s[i] == 'P')
         ++pCount;
     else if (s[i] == 'y' || s[i] == 'Y')
         ++yCount;
 }
 answer = pCount == yCount;

 return answer;
}