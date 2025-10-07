#include <iostream>
using namespace std;

int arr[10];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;

    for (size_t i = 0; i < n; i++)
        cin >> arr[i];

    int answer{};

    for (int i = n-1; i >= 0; i--)
    {
        answer += k / arr[i];
        k %= arr[i];
    }

    cout << answer;

    return 0;
}