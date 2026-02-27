using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <limits>
#include <cctype> 
#include <iomanip>

typedef long long ll;

vector<int> vec;
vector<char> vis;
vector<int> temp;
int answer;
int chack;

void DFS(int depth)
{
    if (depth == 10)
    {
        int count{};
        for (int i = 0; i < 10; i++)
        {
            if (vec[i] == temp[i])
                count++;
        }
        if (count >= 5)
            answer++;
        return;
    }

    // 3개의 연속된 답은 x, 1~5까지
    for (int i = 1; i <= 5; i++)
    {
        temp[depth] = i;

        if (depth >= 2 && temp[depth - 1] == temp[depth] && temp[depth] == temp[depth - 2])
            continue;

        DFS(depth + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vec.assign(10, 0);
    for (int i = 0; i < 10; i++)
        cin >> vec[i];

    temp.assign(10, 0);
    vis.assign(11, false);

    DFS(0);

    cout << answer;
    return 0;
}
