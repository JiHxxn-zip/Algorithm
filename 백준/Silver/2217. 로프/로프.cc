#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    sort(vec.begin(), vec.end());

    int answer{};
    for (int i = 0; i < n; i++)
        answer = max(answer, vec[i] * (n - i));

    cout << answer;

    return 0;
}
