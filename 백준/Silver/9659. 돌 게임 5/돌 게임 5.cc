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

    ll n;
    cin >> n;

    if (n % 2 == 1)
        cout << "SK";
    else
        cout << "CY";

    return 0;
}

