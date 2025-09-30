#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>    
#include "string"
using namespace std;

// 
string a[10001];
string b[10001];

bool isOneInsertOrDelete(const string& s, const string& t) 
{
    if (abs((int)s.size() - (int)t.size()) != 1) 
        return false;

    const string& longer = (s.size() > t.size() ? s : t);
    const string& shorter = (s.size() > t.size() ? t : s);

    int i = 0, j = 0, diff = 0;
    while (i < longer.size() && j < shorter.size()) 
    {
        if (longer[i] != shorter[j]) 
        {
            if (++diff > 1) 
                return false;

            i++; // 긴 쪽에서만 스킵
        }
        else
        {
            i++; 
            j++;
        }
    }
    return true;
};

bool isOneReplace(const string& s, const string& t) 
{
    if (s.size() != t.size()) 
        return false;

    int diff = 0;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] != t[i]) 
        {
            diff++;

            if (diff > 1) 
                return false;
        }
    }
    return diff == 1;  // 반드시 한 글자만 달라야 true
}

bool isOneSwap(const string& s, const string& t) 
{
    if (s.size() != t.size()) 
        return false;

    vector<int> diff;
    for (int i = 0; i < s.size(); i++) 
        if (s[i] != t[i]) diff.push_back(i);

    return (diff.size() == 2 &&
        s[diff[0]] == t[diff[1]] &&
        s[diff[1]] == t[diff[0]]);
};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, q;
    cin >> n;

    for (size_t i = 0; i < n; i++)
        cin >> a[i];

    cin >> q;

    for (size_t i = 0; i < q; i++)
        cin >> b[i];
    
    // a에 저장된 값을 토대로 b의 단어를 판단
    for (size_t i = 0; i < q; i++)
    {
        bool isCorrect = false;
        bool isMiss = false;
        string same = {};

        for (size_t j = 0; j < n; j++)
        {
            if (b[i] == a[j]) 
            {
                cout << b[i] << " is correct\n";
                isCorrect = true;
                break;
            }

            if (isOneInsertOrDelete(b[i], a[j]) ||
                isOneSwap(b[i], a[j]) ||     
                isOneReplace(b[i], a[j]))
            {
                if (!isMiss) 
                    same = a[j];

                isMiss = true;
            }
        }

        if (isCorrect) 
            continue;

        if (isMiss) 
            cout << b[i] << " is a misspelling of " << same << '\n';
        else 
            cout << b[i] << " is unknown\n";
    }

    return 0;
}
