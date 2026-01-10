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

    string a, b;

    while (getline(cin, a))
    {
        getline(cin, b);
        // 문자 a가 몇번 등장했는지, 이미 몇번 사용했는지.

        vector<char> vec;
        for (int i = 0; i < a.size(); i++)
        {
            int idx = b.find(a[i]);

            if (idx != string::npos)
            {
                b[idx] = '_';
                vec.push_back(a[i]);
            }
        }

        if (vec.size() == 1)
            cout << vec[0];
        else
        {
            sort(vec.begin(), vec.end());

            for (int i = 0; i < vec.size(); i++)
                cout << vec[i];
        }

        cout << '\n';

    }

    return 0;
}