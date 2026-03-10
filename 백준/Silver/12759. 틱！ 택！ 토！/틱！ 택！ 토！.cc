using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits>
#include <cctype> 
#include <iomanip>

typedef long long ll;

queue<pair<int, int>> player_O;
queue<pair<int, int>> player_X;

bool IsSolve(int player, int col, int row)
{
    queue<pair<int, int>> temp;
    if (player == 1)
    {
        player_O.push({ col, row });
        temp = player_O;
    }
    else
    {
        player_X.push({ col, row });
        temp = player_X;
    }

    // 세로 3줄, 가로 3줄, 대각선 2줄
    // 123, 456, 789
    // 147, 258, 369
    // 159, 357

    vector<int> result;
    while (!temp.empty())
    {
        auto x = temp.front();
        temp.pop();
        if (x.first == 1)
        {
            result.push_back(x.first * x.second);
        }
        else if (x.first == 2)
        {
            if (x.second == 1)
                result.push_back(4);
            if (x.second == 2)
                result.push_back(5);
            if (x.second == 3)
                result.push_back(6);
        }
        else if (x.first == 3)
        {
            if (x.second == 1)
                result.push_back(7);
            if (x.second == 2)
                result.push_back(8);
            if (x.second == 3)
                result.push_back(9);
        }
    }

    if (find(result.begin(), result.end(), 1) != result.end() &&
        find(result.begin(), result.end(), 2) != result.end() &&
        find(result.begin(), result.end(), 3) != result.end())
        return true;
    else if (find(result.begin(), result.end(), 4) != result.end() &&
        find(result.begin(), result.end(), 5) != result.end() &&
        find(result.begin(), result.end(), 6) != result.end())
        return true;
    else if (find(result.begin(), result.end(), 7) != result.end() &&
        find(result.begin(), result.end(), 8) != result.end() &&
        find(result.begin(), result.end(), 9) != result.end())
        return true;
    else if (find(result.begin(), result.end(), 1) != result.end() &&
        find(result.begin(), result.end(), 4) != result.end() &&
        find(result.begin(), result.end(), 7) != result.end())
        return true;
    else if (find(result.begin(), result.end(), 2) != result.end() &&
        find(result.begin(), result.end(), 5) != result.end() &&
        find(result.begin(), result.end(), 8) != result.end())
        return true;
    else if (find(result.begin(), result.end(), 3) != result.end() &&
        find(result.begin(), result.end(), 6) != result.end() &&
        find(result.begin(), result.end(), 9) != result.end())
        return true;
    else if (find(result.begin(), result.end(), 1) != result.end() &&
        find(result.begin(), result.end(), 5) != result.end() &&
        find(result.begin(), result.end(), 9) != result.end())
        return true;
    else if (find(result.begin(), result.end(), 3) != result.end() &&
        find(result.begin(), result.end(), 5) != result.end() &&
        find(result.begin(), result.end(), 7) != result.end())
        return true;

    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int startPlayer;
    cin >> startPlayer;

    vector<pair<int, int>> vec(9);

    for (int i = 0; i < 9; i++)
    {
        int col, row;
        cin >> col >> row;

        if (IsSolve(startPlayer, col, row))
        {
            cout << startPlayer;
            return 0;
        }
        else
            startPlayer = startPlayer == 1 ? 2 : 1;
    }

    cout << 0;

    return 0;
}
