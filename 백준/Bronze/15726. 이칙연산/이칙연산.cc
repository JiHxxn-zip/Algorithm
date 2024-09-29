#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    long long iA(0), iB(0), iC(0);
    cin >> iA >> iB >> iC;
    cout << max(iA*iB/iC,iA*iC/iB) << endl;
    return 0; 
}