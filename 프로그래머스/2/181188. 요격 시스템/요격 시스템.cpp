using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>

int solution(vector<vector<int>> targets) 
{
    int answer = 1;
    
    sort(targets.begin(), targets.end());
    
    int mn = targets[0][1];
    for(int i = 1; i < targets.size(); ++i)
    {
        if(mn > targets[i][0])
        {
            if(mn > targets[i][1])
                mn = targets[i][1];
        }
        else
        {
            answer++;
            mn = targets[i][1];
        }
    }
    
    return answer;
}

// 시작점을 기준