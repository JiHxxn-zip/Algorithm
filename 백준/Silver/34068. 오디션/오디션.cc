using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <unordered_map>
#include <climits> // INT_MAX

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n, m;
    cin >> n >> m;

    //if (m == 0)
    //{
    //    cout << n;
    //    return 0;
    //}

    vector<long long> vec(n);
    for (long long i = 0; i < m; i++)
    {
        long long a, b;
        cin >> a >> b;

        vec[a-1]++;
    }
    
    sort(vec.begin(), vec.end());

    long long result{}, count{};
    for (long long i = 1; i < vec.size(); i++)
    {
        long long o = vec[i] - vec[i - 1];
        count = 0;
        if (o <= 0)
        {
            vec[i] += abs(o) + 1;
            count = abs(o) + 1;
        }
        result += count;
    }
    
    cout << result;

    return 0;
}

// m개의 줄에 걸쳐 i + 1 번째 줄에는 i번째 결투의 결과가 주어짐
// Ai, Bi -> Ai가 승리