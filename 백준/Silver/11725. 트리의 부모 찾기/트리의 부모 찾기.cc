using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

vector<int> vec[100001];
int nodes[100001];

void DFS(int cur)
{
    // cur이 부모
    for (auto next : vec[cur])
    {
        // 방향이 없는 그래프 이기 때문에 부모로 돌아가는 걸 막기 위한 조건문
        if (nodes[cur] == next)
            continue;

        nodes[next] = cur;
        DFS(next);
    }
}

void BFS()
{
    queue<int> q;
    q.push(1);
    nodes[1] = 1;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        // cur이 부모
        for (auto next : vec[cur])
        {
            if (nodes[next] == 0)
            {
                nodes[next] = cur;
                q.push(next);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    //DFS(1);
    BFS();
    for (int i = 2; i <= n; i++)
        cout << nodes[i] << '\n';

    return 0;
}

// 트리 문제
// 1을 최상위 루트로 생각하고, 2부터 자신의 부모 노드 출력