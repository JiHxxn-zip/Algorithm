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

    int n;
    cin >> n;

    vector<int> total(2 * n, 1);

    vector<int> s(n);
    vector<int> k;
    k.reserve(n);

    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        total[s[i]-1]--;
    }

    for (int i = 0; i < total.size(); i++)
    {
        if (total[i] == 1)
            k.push_back(i + 1);
    }

    /*  다음 규칙에 따라 교대로 카드를 1장씩 낸다.
        놓여진 카드가 없다면 원하는 카드를 낼 수 있다.
        놓여진 카드가 있다면 마지막에 나온 카드보다 큰 숫자가 적힌 카드를 낼 수 있다.
        낼 카드가 없는 경우 상대의 차례가 된다.이때, 자리에 나와있는 카드는 없어진다.
        게임은 카드가 아무 것도 놓여있지 않은 상태에서 시작한다.
        둘 중 한 명이라도 카드를 모두 사용하면 게임이 종료된다.
        게임 종료시 상대방이 가지고 있는 카드의 수를 점수로 획득한다.*/

    sort(s.begin(), s.end());
    sort(k.begin(), k.end());

    bool turn_S = true;
    int last{};
    while (!s.empty() && !k.empty())
    {
        if (turn_S)
        {
            auto it = upper_bound(s.begin(), s.end(), last);
            if (it != s.end())
            {
                last = *it;
                s.erase(it);
            }
            else
                last = 0;
         
            turn_S = false;
        }
        else
        {
            auto it = upper_bound(k.begin(), k.end(), last);
            if (it != k.end())
            {
                last = *it;
                k.erase(it);
            }
            else
                last = 0;

            turn_S = true;
        }
    }

    cout << k.size() << '\n' << s.size();

    return 0;
}
