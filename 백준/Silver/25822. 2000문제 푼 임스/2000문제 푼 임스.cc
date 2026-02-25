using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include <limits>
#include <cctype> 
#include <iomanip>

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    float coin;
    int n;
    cin >> coin >> n;

    vector<int> vec(n);
    int mxAnswer = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
        mxAnswer = max(mxAnswer, vec[i]);
    }

    int left = 0;
    int zero = 0;
    int mx = 0;

    if (coin > 2)
        coin = 2;

    for (int right = 0; right < n; right++)
    {
        if (vec[right] == 0)
            zero++;

        while (zero > coin)
        {
            if (vec[left] == 0)
                zero--;
            left++;
        }

        mx = max(mx, right - left + 1);
    }

    cout << mx << '\n' << mxAnswer;
}
