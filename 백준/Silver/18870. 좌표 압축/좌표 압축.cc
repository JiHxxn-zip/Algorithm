#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int x[1000005];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> uni;
    uni.reserve(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        uni.push_back(x[i]);
    }
 
    sort(uni.begin(), uni.end());
    uni.erase(unique(uni.begin(), uni.end()), uni.end());

    for (int i = 0; i < n; i++)
        cout << lower_bound(uni.begin(), uni.end(), x[i]) - uni.begin() << ' ';
    
    return 0;
}