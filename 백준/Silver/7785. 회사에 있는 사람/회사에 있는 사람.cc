using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>    
#include <unordered_set>

unordered_set<string> s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = 0;
    cin >> n;

    while (n--)
    {
        string name{}, log{};
        cin >> name >> log;
        if (log == "enter")
            s.insert(name);
        else
            s.erase(name);
    }

    vector<string> ans(s.begin(), s.end());
    sort(ans.begin(), ans.end(), greater<string>());

    for (auto name : ans)
        cout << name << '\n';
    return 0;
}

