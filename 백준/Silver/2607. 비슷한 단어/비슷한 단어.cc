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

    int N;
    cin >> N;

    string first;
    cin >> first;
    
    vector<int> base(26, 0);
    for (char c : first)
        base[c - 'A']++;

    int result{};

    for (int i = 0; i < N-1; i++)
    {
        string s;
        cin >> s;

        vector<int> cnt = base;
        int same{};

        // s의 글자를 기준에서 하나씩 소비 해보기
        for (char c : s)
        {
            int idx = c - 'A';
            if (cnt[idx] > 0)
            {
                cnt[idx]--;
                same++;
            }
        }

        int lenA = first.size();
        int lenB = s.size();

        // 단어 판정
        if (lenA == lenB)
        {
            // 같은 길이 : 교체 1번까지 허용 -> 공통이 lenA or lenA-1
            if (same == lenA || same == lenA - 1)
                result++;
        }
        else if (lenA + 1 == lenB)
        {
            if (same == lenA)
                result++;
        }
        else if (lenA - 1 == lenB)
        {
            if (same == lenB)
                result++;
        }
    }
    cout << result;

    return 0;
}