using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
#include <cctype> 
#include <iomanip>

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    int totalCount{};
    int maxCount{};
    string maxName{};
    for (int i = 0; i < n; i++)
    {
        string p;
        cin >> p;
        
        int k, m; // 필요한 사탕의 수 k, 가지고 있는 사탕의 수
        cin >> k >> m;


        int plus{};

        while (m >= k)
        {
            int mod = m / k;
            plus += mod;
            m = (m % k) + (mod * 2);
        }

        totalCount += plus;
        if (plus > maxCount)
        {
            maxCount = plus;
            maxName = p;
        }
    }

    cout << totalCount << '\n' << maxName;
    return 0;
}