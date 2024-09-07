#include<iostream>
#include <deque>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   

    deque<int> dq;
    vector<bool> vec;
    
    int iSize(0), iInput(0);

    cin >> iSize;
    vec.reserve(iSize);

    for (int i = 0; i < iSize; ++i)
    {
        cin >> iInput;
        vec.push_back(iInput);
    }

    for (int i = 0; i < iSize; ++i)
    {
        cin >> iInput;
        if (vec[i]) continue;
        
        dq.push_back(iInput);
    }

    cin >> iSize;
    for (int i = 0; i < iSize; ++i)
    {
        cin >> iInput;
        dq.push_front(iInput);
        cout << dq.back() << ' ';
        dq.pop_back();
    }

    return 0;
}
