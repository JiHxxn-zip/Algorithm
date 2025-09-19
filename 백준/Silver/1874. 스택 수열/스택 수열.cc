#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include "algorithm"
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n{};
    cin >> n;
    
    stack<int> s;
    vector<char> answer;
    int cur{ 1 };
    bool possible{true};

    for (size_t i = 0; i < n; i++)
    {
        int x{};
        cin >> x;
        
        while (cur <= x)
        {
            s.push(cur);
            answer.push_back('+');
            ++cur;  
        }

        if (x == s.top())
        {
            s.pop();
            answer.push_back('-');
        }
        else
            possible = false;
    }
    
    if (!possible)
        cout << "NO";
    else
    {
        for (size_t i = 0; i < answer.size(); i++)
        {
            cout << answer[i] << '\n';
        }
    }

    return 0;
}       
