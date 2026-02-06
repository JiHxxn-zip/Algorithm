using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cctype> 
#include <iomanip>
#include <unordered_map>

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

    unordered_map<int, int> maxValue;
    int result{};
    
    // 첫 윈도우
    for (int i = 0; i < m; i++)
    {
        maxValue[vec[i]]++;
        result = max(result, maxValue[vec[i]]);
    }

    for (int i = 0; i < n-m; i++)
    {
        maxValue[vec[i]]--;
        maxValue[vec[m + i]]++;

        result = max(result, maxValue[vec[m + i]]);
    }
    
    if (result * 10 >= m * 9)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}