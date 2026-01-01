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

    vector<string> vec(n * 2 - 1);

    int strCount = 0;
    for (int i = 0; i < (int)vec.size(); i += 2) {
        cin >> vec[i];
        strCount += (int)vec[i].size();
    }

    if (n == 1) {
        cout << vec[0];
        return 0;
    }

    int gaps = n - 1;
    int needCount = m - strCount;

    int q = needCount / gaps;
    int r = needCount % gaps;

    // 기본 q개씩 모든 간격에 채우기
    for (int i = 1; i < (int)vec.size(); i += 2)
        vec[i].append(q, '_');

    // 추가 r개: 앞에서부터(소문자 시작 간격 우선)
    for (int i = 0; i < gaps && r > 0; ++i) 
    {
        int space = 2 * i + 1;
        int nextIndex = 2 * i + 2;
        unsigned char c = (unsigned char)vec[nextIndex][0];

        if (islower(c)) 
        {
            vec[space].push_back('_');
            --r;
        }
    }

    // 3) 남은 r개: 뒤에서부터(대문자 시작 간격)
    for (int i = gaps - 1; i >= 0 && r > 0; --i) 
    {
        int space = 2 * i + 1;
        int nextIndex = 2 * i + 2;
        unsigned char c = (unsigned char)vec[nextIndex][0];

        if (!islower(c)) 
        {
            vec[space].push_back('_');
            --r;
        }
    }

    for (auto& s : vec) 
        cout << s;

    return 0;
}

// vector로 string 저장
// 주어진 문자열의 갯수를 누적한 값을 m에서 빼줌
// 빼준 값을 나눠서 _를 넣어주면 되는데
// dp?
// 배열의 사이즈 -1 에 넣어줘야하는데
// _갯수가 <= 1