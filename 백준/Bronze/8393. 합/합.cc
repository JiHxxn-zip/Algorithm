#include<iostream>
using namespace std;

int main()
{
    int iInput(0), iSum(0);
    cin >> iInput;

    while (true)
    {
        iSum += iInput;
        --iInput;
        if (iInput == 0)
        {
            cout << iSum;
            break;
        }
    }
    
    return 0;
}