#include <string>
#include <vector>

using namespace std;

// DFS 함수
void DFS(vector<int> numbers, int target, int curIndex, int curVaule);
int answer = 0;

int solution(vector<int> numbers, int target) 
{
    DFS(numbers, target, 0, 0);
    return answer;
}

void DFS(vector<int> numbers, int target, int curIndex, int curVaule)
{
    // 예외처리 작성 
    if (curIndex == numbers.size())
    {
        if (target == curVaule)
            ++answer;
        
        return;
    }

    DFS(numbers, target, curIndex + 1, curVaule + numbers[curIndex]);
    DFS(numbers, target, curIndex + 1, curVaule - numbers[curIndex]);
}
