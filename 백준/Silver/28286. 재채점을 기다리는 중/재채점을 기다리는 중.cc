using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <climits>
#include <cctype> 
#include <iomanip>

int N, K;
vector<int> MAP, Correct;
int Answer;

void DFS(int depth, vector<int> vec)
{
    // 현재 점수
    int cnt{};
    for (int i = 0; i < N; i++) 
    {
        if (Correct[i] == vec[i]) 
            cnt++;
    }
    Answer = max(Answer, cnt);

    if (depth == K) 
        return;

    for (int i = 0; i < N; i++) 
    {
        // pull (i..N-1 구간을 왼쪽으로 당김)
        {
            vector<int> tmp = vec;
            for (int j = i; j < N - 1; j++) 
                tmp[j] = tmp[j + 1];

            tmp[N - 1] = 0;
            DFS(depth + 1, tmp);
        }

        // push (i..N-1 구간을 오른쪽으로 밈)
        {
            vector<int> tmp = vec;
            for (int j = N - 1; j > i; j--) 
                tmp[j] = tmp[j - 1];

            tmp[i] = 0;
            DFS(depth + 1, tmp);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> K;
    Correct.resize(N);
    MAP.resize(N);

    for (int i = 0; i < N; i++) 
        cin >> Correct[i];
    
    for (int i = 0; i < N; i++)
        cin >> MAP[i];

    DFS(0, MAP);
    cout << Answer;

    return 0;
}