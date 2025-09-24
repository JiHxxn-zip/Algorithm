#include <iostream>
#include <vector>
#include "algorithm"
using namespace std;

int n, m;
bool vis[10];
int answer[10];

// 현재 인덱스와, 사용된 숫자
void DFS(int curIndex)
{
    // m과 현재 인덱스와 같을 때 출력
    if (m == curIndex)
    {
        for (size_t i = 0; i < m; i++)
            cout << answer[i] << ' ';
        
        cout << '\n';
        return;
    }

    for (size_t i = 0; i < n; i++)
    {
        if (vis[i] == false)
        {
            answer[curIndex] = i + 1;

            vis[i] = true;
            DFS(curIndex + 1);
            vis[i] = false;
        }
    }

    return;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    // 1부터 n번까지 자연수를 중복없이 m개의 수열
    DFS(0);

    return 0;
}       

