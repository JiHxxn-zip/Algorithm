#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "algorithm"
using namespace std;

int dist[100002]; 

int n, k;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    queue <int> q;
    q.push(n);

    fill(dist, dist + 100001, -1);
    dist[n] = 0;
    while (dist[k] == -1)
    {
        int cur = q.front();
        q.pop();

        for (int next : {cur + 1, cur - 1, cur * 2})
        {
            if (next < 0 || next > 100000)
                continue;
            if (dist[next] != -1)
                continue;

            dist[next] = dist[cur] + 1;
            q.push(next);
        }
    }

    cout << dist[k];

    return 0;
}       

// 1차원 BFS
// 100000의 사이즈가 주어졌지만 2명을 더해 1000002 셋팅
// dist -1 셋팅해주기
// for문으로 상하좌우가 아닌 -1, +1, *2로 다음 갈 곳 정리
// 조건문으로 100000밖으로 나가거나 dist로 0>= 이면 continue
// 출력은 도착 지점의 dist