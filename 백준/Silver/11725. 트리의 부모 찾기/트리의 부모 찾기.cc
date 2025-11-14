using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

vector<int> vec[100001];
int parent[100001];

void BFS()
{
    queue<int> q;
    q.push(1);
    parent[1] = 1;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (auto next : vec[cur])
        {
            if (parent[next] == 0)
            {
                parent[next] = cur;
                q.push(next);
            }
        }
    }
}

void DFS(int n)
{
    for (auto next : vec[n])
    {
        if (parent[next] == 0)
        {
            parent[next] = n;
            DFS(next);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    //DFS(1);
    BFS();
    
    for (int i = 2; i <= n; i++)
        cout << parent[i] << '\n';

    return 0;
}

// 부모 노드 출력(2부터)
// 1을 루트 노드라고 생각하고 진행
// BFS와 DFS로 검사 후 출력
// 부모 노드를 저장해줄 배열에 저장 후 값이 있으면 continue