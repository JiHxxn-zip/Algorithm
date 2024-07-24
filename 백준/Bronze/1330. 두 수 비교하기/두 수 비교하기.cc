#include<iostream>
using namespace std;

int main()
{
    int iA(0), iB(0);
    cin >> iA;
    cin >> iB;
    
    if(iA > iB)
    {
        cout << ">";
    }
    else if(iA < iB)
    {
        cout << "<";
    }
    else if(iA == iB)
    {
        cout << "==";
    }
    
    
    return 0;
}