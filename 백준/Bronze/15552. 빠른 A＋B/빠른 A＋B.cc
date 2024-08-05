#include<iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int iInput(0), iA(0), iB(0);
    cin >> iInput;

    for (int i = 0; i < iInput; ++i)
    {
	    cin >> iA >> iB;
	    cout << iA + iB << '\n';
    }
    
    return 0;
}