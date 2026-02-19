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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while (T--) 
    {
        int A, B;
        cin >> A >> B;

        vector<bool> visited(10000, false);
        vector<int> parent(10000, -1);
        vector<char> command(10000);

        queue<int> q;
        q.push(A);
        visited[A] = true;

        while (!q.empty()) 
        {
            int cur = q.front();
            q.pop();

            if (cur == B) 
                break;

            int d = (cur * 2) % 10000;
            int s = (cur == 0) ? 9999 : cur - 1;
            int l = (cur % 1000) * 10 + (cur / 1000);
            int r = (cur % 10) * 1000 + (cur / 10);

            if (!visited[d])
            {
                visited[d] = true;
                parent[d] = cur;
                command[d] = 'D';
                q.push(d);
            }

            if (!visited[s]) 
            {
                visited[s] = true;
                parent[s] = cur;
                command[s] = 'S';
                q.push(s);
            }

            if (!visited[l]) 
            {
                visited[l] = true;
                parent[l] = cur;
                command[l] = 'L';
                q.push(l);
            }

            if (!visited[r]) 
            {
                visited[r] = true;
                parent[r] = cur;
                command[r] = 'R';
                q.push(r);
            }
        }

        string result{};
        int cur = B;

        while (cur != A) 
        {
            result += command[cur];
            cur = parent[cur];
        }

        reverse(result.begin(), result.end());

        cout << result << "\n";
    }

    return 0;
}