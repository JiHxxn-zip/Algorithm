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
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int s = n * 2 - 1;
    vector<string> vec(s);

    int strCount{};
    for (int i = 0; i < s; i+=2)
    {
        cin >> vec[i];
        strCount += vec[i].size();
    }

    int needCount = m - strCount;

    int eqaul = needCount / (n - 1);
    int remain = needCount % (n - 1);

    for (int i = 1; i < s; i+=2)
    {
        vec[i].append(eqaul, '_');
    }

    for (int i = 0; i < n-1 && remain > 0; i++)
    {
        int space = 2 * i + 1;
        int next = 2 * i + 2;
        unsigned char c = static_cast<unsigned char>(vec[next][0]);

        if (islower(c))
        {
            vec[space].push_back('_');
            --remain;
        }
    }

    for (int i = n -1 -1; i >= 0 && remain > 0; --i)
    {
        int space = 2 * i + 1;
        int next = 2 * i + 2;
        unsigned char c = static_cast<unsigned char>(vec[next][0]);

        if (!islower(c))
        {
            vec[space].push_back('_');
            --remain;
        }
    }

    for (auto a : vec)
        cout << a;

    return 0;
}

