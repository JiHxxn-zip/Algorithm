#include<iostream>
using namespace std;

int main()
{
    int iA(0), iB(0), iC(0), iSum(0);;
    cin >> iA >> iB >> iC;

    if (iA == iB && iA == iC)
    {
        iSum = 10000 + (iA * 1000);
    }
    else if (iA == iB)
    {
        iSum = 1000 + (iA * 100);
    }
    else if (iA == iC)
    {
        iSum = 1000 + (iA * 100);
    }
    else if (iB == iC)
    {
        iSum = 1000 + (iB * 100);
    }
    else if (iA != iB && iA != iC && iB != iC)
    {
        int max = iA > iB ? iA : iB;
        max = max > iC ? max : iC;

        iSum = max * 100;
    }

    cout << iSum;

    return 0;
}
