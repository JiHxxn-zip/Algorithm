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

    int n, m, k;
    cin >> n >> m >> k;
    int sum = m * k;

    vector<int> vec(n);
    int vecSum{};
    
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
        vecSum += vec[i];
    }

    if (sum > vecSum)
    {
        cout << "STRESS";
        return 0;
    }

    sort(vec.rbegin(), vec.rend());

    int result{};



    for (int i = 0; i < n; i++)
    {
        sum -= vec[i];
        result++;
        if (sum <= 0)
            break;
    }
    cout << result;

    return 0;
}