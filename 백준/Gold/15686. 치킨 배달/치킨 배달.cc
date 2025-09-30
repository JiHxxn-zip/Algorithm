#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>    // INT_MAX
using namespace std;

int n, m;

int board[51][51];

vector<pair<int, int>> chicken;
vector<pair<int, int>> house;

// 최소값을 뽑아줄 거기 때문에 intMax값으로 초기화
int mn = INT_MAX;

void DFS(int idx, int cnt);
// 선택된 치킨집 인덱스를 담는 벡터
vector<int> selected;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    // Board 및 치킨집, 집 초기화
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            cin >> board[i][j];
            
            if (board[i][j] == 1)
                house.push_back({i, j});
            else if (board[i][j] == 2)
                chicken.push_back({i, j});
        }
    }
    
    DFS(0, 0);
    cout << mn;

    return 0;
}

// 현재 선택 개수, 시작 인덱스
void DFS(int idx, int cnt) 
{
    // DFS 예외처리
    if (cnt == m) 
    {
        // 치킨 거리 계산
        int dist = 0;
        for (auto h : house) 
        {
            int temp = INT_MAX;
            for (int c : selected) 
            {
                temp = min(temp,
                    abs(chicken[c].first - h.first) +
                    abs(chicken[c].second - h.second));
            }
            dist += temp;
        }
        mn = min(mn, dist);
        return;
    }

    if (idx >= (int)chicken.size()) return;

    // 1. 현재 idx 치킨집을 선택
    selected.push_back(idx);
    DFS(idx + 1, cnt + 1);
    selected.pop_back();

    // 2. 현재 idx 치킨집을 선택하지 않음
    DFS(idx + 1, cnt);
}
