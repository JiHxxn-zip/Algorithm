    using namespace std;
    #include <iostream>
    #include <algorithm>
    #include <vector>
    #include <climits>    

    int board[51][51];
    int n, m;
    int mn = INT_MAX;
    vector<pair<int, int>> house;
    vector<pair<int, int>> chicken;

    // 선택된 치킨 집 관리
    vector<int> selected;

    void DFS(int idx, int depth);

    int main() 
    {
        ios::sync_with_stdio(false);
        cin.tie(0);

        cin >> n >> m;

        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                cin >> board[i][j];

                if (board[i][j] == 1)
                    house.push_back({ i, j });
                if (board[i][j] == 2)
                    chicken.push_back({ i, j });
            }
        }

        DFS(0, 0);

        cout << mn;

        return 0;
    }

    void DFS(int idx, int depth)
    {
        if (m == depth)
        {
            int dist{};
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

        if (idx >= chicken.size())
            return;

        selected.push_back(idx);
        DFS(idx+1, depth+1);
        selected.pop_back();

        DFS(idx + 1, depth);
    }