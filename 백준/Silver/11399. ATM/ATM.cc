using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits>
#include <cctype> 
#include <iomanip>

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];
  
    sort(vec.begin(), vec.end());

    int sum{}, temp{};
    for (int i = 0; i < n; i++)
    {
        temp += vec[i];
        sum += temp;
    }
    cout << sum;

    return 0;
}
