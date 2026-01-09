using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <climits>
#include <cctype> 


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> vec(n);

    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    sort(vec.rbegin(), vec.rend());

    queue<int> q;
    for (auto& a : vec)
    {
        q.push(a);
    }

    int a{}, b{};
    a = n / 3;
    b = n & 3;

    int sum{};

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            sum += q.front();
            q.pop();
        }
        q.pop();
    }

    while (!q.empty())
    {
        sum += q.front();
        q.pop();
    }

    cout << sum;

    return 0;
}

// n을 3으로 나눈값, 나머지 값을 추출 
// 3묶음은 가장 큰값들을 모아 2개 추출