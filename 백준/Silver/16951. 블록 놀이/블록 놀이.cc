using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <limits>
#include <cctype> 
#include <iomanip>

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int minAnswer = numeric_limits<int>::max();

    for (int pivot = 0; pivot < n; pivot++) 
    {
        vector<int> temp(n);
        temp[pivot] = a[pivot];

        bool impos = false;

        for (int j = pivot - 1; j >= 0; j--) 
        {
            temp[j] = temp[j + 1] - k;
            if (temp[j] < 1) 
            { 
                // 높이는 1 이상
                impos = true;
                break;
            }
        }
        if (impos) 
            continue;

        for (int j = pivot + 1; j < n; j++) 
        {
            temp[j] = temp[j - 1] + k;
        }

        int cnt = 0;
        for (int idx = 0; idx < n; idx++) 
        {
            if (a[idx] != temp[idx]) cnt++;
        }

        minAnswer = min(minAnswer, cnt);
    }

    cout << minAnswer << "\n";
    return 0;
}