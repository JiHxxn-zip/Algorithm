using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <limits>
#include <cctype> 
#include <iomanip>
#include <queue>

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
   
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];
   
    sort(vec.begin(), vec.end());

    int en{};
    int answer = numeric_limits<int>::max();
    
    for (int st = 0; st < n; st++)
    {
        while (en < n && vec[en] - vec[st] < m)
            en++;

        if (en == n)
            break;

        answer = min(answer, vec[en] - vec[st]);
    }

    cout << answer;

    return 0;
}
