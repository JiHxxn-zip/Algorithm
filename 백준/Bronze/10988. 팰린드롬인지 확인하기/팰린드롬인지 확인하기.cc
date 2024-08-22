#include<iostream>
using namespace std;

int main()
{
	string strName("\0");
	int iMaxSize(0);

	cin >> strName;
	iMaxSize = strName.length();

	for (int i = 0; i < (iMaxSize + 1) / 2; ++i)
	{
		if (strName[i] != strName[iMaxSize-1])
		{
			putchar('0');
			return 0;
		}

		--iMaxSize;
	}

	putchar('1');


	return 0;
}