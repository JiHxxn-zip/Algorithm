using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    
    vector<string> vec;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        bool sameGroup = false;
        for (auto& r : vec)
        {
            if (r.size() == s.size() && ((s + s).find(r) != string::npos))
            {
                sameGroup = true;
                break;
            }
        }

        if (!sameGroup)
            vec.push_back(s);
    }

    cout << vec.size();

    return 0;
}
