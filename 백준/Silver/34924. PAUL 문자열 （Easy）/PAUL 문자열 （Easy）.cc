using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <climits>
#include <cctype> 
#include <iomanip>


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    string paul;
    cin >> paul;

    vector<char> vec;
    for (int i = 0; i < n; i++)
    {
        if (paul[i] == 'P' || paul[i] == 'A' || paul[i] == 'U' || paul[i] == 'L')
        {
            vec.push_back(paul[i]);
        }
        else
            i += 1;

        if (n == i)
        {
            cout << "NO";
            return 0;
        }
    }

    string result{};
    for (auto& a : vec)
        result += a;

    cout << (result == "PAUL" ? "YES" : "NO");
    return 0;
}

