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

    long long n;
    cin >> n;
    string cupon{}, a{};
    cin >> cupon >> a;

    for (char& ch : cupon)
    {
        if (ch == '?')
            ch = '9';
    }

    if (cupon.size() > a.size())
        cout << cupon;
    else if (cupon.size() < a.size())
        cout << -1;
    else
    {
        if (cupon >= a)
            cout << cupon;
        else
            cout << -1;
    }

    return 0;
}
