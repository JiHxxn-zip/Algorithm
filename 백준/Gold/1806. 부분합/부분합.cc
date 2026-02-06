using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cctype> 
#include <iomanip>

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, s;
    cin >> n >> s;

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];

    int en{}, total = vec[0];
    int answer = INT_MAX;
    
    for (int st = 0; st < n; st++)
    {
        while (en < n && total < s)
        {
            en++;
            if (en != n)
                total += vec[en];
        }

        if (en == n)
            break;

        answer = min(answer, en - st + 1);
        total -= vec[st]; // 이동할 걸 대비해 빼줌
    }

    if (answer == INT_MAX)
        answer = 0;

    cout << answer;

    return 0;
}