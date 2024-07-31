#include<iostream>
using namespace std;

int main()
{
	char szName[1024]{};
	int iIndex(0);
	cin >> szName;
	cin >> iIndex;
	cout << szName[iIndex-1];
    
    return 0;
}