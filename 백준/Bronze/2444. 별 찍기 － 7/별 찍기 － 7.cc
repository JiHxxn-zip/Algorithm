#include<iostream>
using namespace std;

int main()
{
	int iCount(0), iTemp(0);
	cin >> iCount;

	for (int i = 0; i < iCount; ++i)
	{
		for (int j = 0; j < iCount; ++j)
		{
			if (iCount - 1 > i + j)
				putchar(' ');
			else
				break;
		}

		for (int k = 0; k < i * 2 + 1; ++k)
			putchar('*');

		cout << endl;
	}

	iTemp = iCount * 2 - 3;

	for (int i = 1; i <= iCount; ++i)
	{
		for (int j = 0; j < iCount; ++j)
		{
			if (i > j)
				putchar(' ');
			else
				break;
		}

		for (int k = 0; k < iTemp; ++k)
			putchar('*');
		
		iTemp -= 2;
		if (-1 == iTemp)
			break;

		cout << endl;
	}

	return 0;
}