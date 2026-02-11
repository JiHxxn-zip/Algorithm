using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <limits>
#include <cctype> 
#include <iomanip>
#include <unordered_map>

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        auto it = lower_bound(vec.begin(), vec.end(), x);
        if (it == vec.end())
            vec.push_back(x);
        else
            *it = x;
    }

    cout << vec.size();
   
    return 0;
}
