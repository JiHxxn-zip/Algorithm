using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <limits>
#include <cctype> 
#include <iomanip>

typedef long long ll;

int minAnswer = numeric_limits<int>::max();
vector<char> vis;
vector<int> p;
vector<int> vec;

bool AnswerCheck(const vector<int>& p) 
{
    // 가로 합
    if (p[0] + p[1] + p[2] != 15) 
        return false;
    if (p[3] + p[4] + p[5] != 15) 
        return false;
    if (p[6] + p[7] + p[8] != 15) 
        return false;

    // 세로 합
    if (p[0] + p[3] + p[6] != 15) 
        return false;
    if (p[1] + p[4] + p[7] != 15) 
        return false;
    if (p[2] + p[5] + p[8] != 15) 
        return false;

    // 대각선 합
    if (p[0] + p[4] + p[8] != 15) 
        return false;
    if (p[2] + p[4] + p[6] != 15) 
        return false;

    return true;
}

void DFS(int depth)
{
    if (depth == 9)
    {
        if (AnswerCheck(p))
        {
            int cur{};
            for (int i = 0; i < 9; i++)
                cur += abs(vec[i] - p[i]);
            
            minAnswer = min(minAnswer, cur);
        }
        return;
    }

    for (int i = 1; i <= 9; i++)
    {
        if (vis[i])
            continue;
        p[depth] = i;
        vis[i] = true;
        DFS(depth + 1);
        vis[i] = false;
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    vec.assign(9, 0);
    for (int i = 0; i < 9; i++)
        cin >> vec[i];

    p.assign(9, 0);
    vis.assign(10, 0);
    
    DFS(0);

    cout << minAnswer;
    return 0;
}
