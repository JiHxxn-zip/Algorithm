#include <iostream>
#include <algorithm>
using namespace std;
int a[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int x;
    cin >> x;

    sort(a, a+n);

    int left = 0;
    int right = n-1;
    int answer = 0;

    while (left < right) {
        int temp = a[left] + a[right];
        if (temp < x) {
            left++;
        } else if (temp > x) {
            right--;
        } else {
            left++; right--;
            answer++;
        }
    }

    cout << answer;

    return 0;
}