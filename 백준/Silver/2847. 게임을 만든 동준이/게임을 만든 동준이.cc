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
    
    int n;
    cin >> n;

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    int count{};
    for (int i = n-2; i >= 0; i--) // 뒤에서 부터 순회. 작게 빼는거
    {
        if (vec[i] >= vec[i + 1]) // 만약 뒤보다 크다면 줄여야하함
        {
            int add = vec[i] - vec[i + 1] + 1;
            count += add;
            vec[i] -= add;
        }
    }
    cout << count;

    return 0;
}