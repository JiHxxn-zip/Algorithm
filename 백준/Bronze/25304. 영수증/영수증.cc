#include<iostream>
using namespace std;

int main()
{
    int iSum(0), iCount(0), iMoney(0), iMoneyCount(0), iResult(0);
    cin >> iSum;
    cin >> iCount;

    for (int i = 0; i < iCount; ++i)
    {
	    cin >> iMoney >> iMoneyCount;

	    iResult += iMoney * iMoneyCount;
    }
    
    if (iResult == iSum)
    {
	    cout << "Yes" << endl;
    }
    else
    {
	    cout << "No" << endl;
    }
    return 0;
}