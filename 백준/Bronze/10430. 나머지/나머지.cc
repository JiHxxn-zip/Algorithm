#include<iostream>
using namespace std;

int main()
{
    int iA(0), iB(0), iC(0);
    cin >> iA >> iB >> iC;

    cout << (iA + iB) % iC << endl
    << ((iA % iC) + (iB % iC)) % iC << endl
    << (iA * iB) % iC << endl
    << ((iA % iC) * (iB % iC)) % iC;
    return 0;
}