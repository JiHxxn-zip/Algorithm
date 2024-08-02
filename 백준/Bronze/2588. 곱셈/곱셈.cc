#include<iostream>
using namespace std;

int main()
{
    int iA(0), iB(0);
    cin >> iA >> iB;

    int a(0), b(0), c(0);

    a = iB / 100;
    iB %= 100;

    b = iB / 10;
    iB %= 10;

    c = iB;

    cout << iA*c << endl << iA*b << endl << iA*a << endl << iA*(a*100+b*10+c);
    
    return 0;
}