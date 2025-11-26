using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>

map<string, string> m;
map<string, bool> isVisited;

int answer;

void DFS(string name)
{
    if (isVisited[m[name]])
        answer++;
    else
    {
        isVisited[m[name]] = true;
        DFS(m[name]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int i{};

    while (cin >> n)
    {
        if (n == 0)
            break;

        answer = 0;

        isVisited.clear();
        m.clear();

        while (n--)
        {
            string name1, name2;
            cin >> name1 >> name2;
            m[name1] = name2;
        }

        for (auto p : m)
        {
            if (isVisited[p.first])
                continue;

            DFS(p.first);
        }

        std::cout << ++i << ' ' << answer << '\n';
    }

    return 0;
}