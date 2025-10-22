using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    unordered_map<string, int> s2i;
    vector<string> i2s(n+1);
    
    for (int i = 1; i <= n; i++)
    {
        cin >> i2s[i];
        s2i[i2s[i]] = i;
    }

    while (m--)
    {
        string a{};
        cin >> a;
        if (isdigit(a[0]))
            cout << i2s[stoi(a)] << '\n';
        else
            cout << s2i[a] << '\n';
    }
    
    return 0;
}