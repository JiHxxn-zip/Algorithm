#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include "algorithm"
using namespace std;


vector<int> solution(vector<int> progresses, vector<int> speeds) {
        vector<int> answer;
    queue<int> q;

    for (size_t i = 0; i < progresses.size(); i++)
    {
        // 100 에서 뺸 값에서 speeds를 나누고 나머지가 있다면 +1
        int count = 0;
        count = (100 - progresses[i]) / speeds[i];
        if ((100 - progresses[i]) % speeds[i])
            ++count;

        q.push(count);
    }

    int count{ 0 };
    // 하나 뽑고 그 이후꺼 
    int temp = q.front();
    q.pop();
    ++count;

    while (!q.empty())
    {
        // 현재 일차가 다음 일보다 크면 올려주고 뽑아
        if (temp >= q.front())
        {
            ++count;
        }
        else    // 갈아껴야돼
        {
            answer.push_back(count);

            count = 1;

            temp = q.front();
           
        }
        q.pop();
    }

    answer.push_back(count);

    return answer;
}