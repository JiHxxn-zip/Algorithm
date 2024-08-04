#include<iostream>
using namespace std;

int main()
{
    int iInput(0);
    int iA(0), iB(0);
    cin >> iInput;

    for (int i = 0; i < iInput; ++i)
    {
        cin >> iA >> iB;

        cout << iA+iB<< endl;
    }
    
    return 0;
}