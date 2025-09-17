#include <iostream>
#include <vector>
#include "algorithm"
using namespace std;

// 완료한 단어를 체크하기 위한 방문 변수
bool vis[51];
int answer{ 51 };

bool Cheke_Words(string cur, string target)
{
    int diff{};
    for (size_t i = 0; i < cur.size(); i++)
    {
        if (cur[i] != target[i])
            ++diff;

        if (diff > 1) 
            return false; // 2글자 이상 다르면 탈락
    }
    return diff == 1;
}

void DFS(string word, string target, vector<string> words, int count)
{
    // 같다면 탈출
    if (word == target)
    {
        answer = min(answer, count);
        return;
    }

    // 전수검사가 필요
    for (size_t i = 0; i < words.size(); i++)
    {
        // 방문하지 않은 단어와, 내가 바꿀 단어가 있는지 체크 해야되는데,
        if (!vis[i] && Cheke_Words(word, words[i]))
        {
            vis[i] = true;
            DFS(words[i], target, words, count+1);
            vis[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) 
{
    // 예외처리.
    if (find(words.begin(), words.end(), target) == words.end())
        return 0;

    // 시작
    DFS(begin, target, words, 0);

    return (answer == 51 ? 0 : answer);
}