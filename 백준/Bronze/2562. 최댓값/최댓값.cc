#include<iostream>
using namespace std;

int main()
{
	int iArray[9]{};
	int iCount(0), iMax(0);

	for (int i = 0; i < size(iArray); i++)
	{
		cin >> iArray[i];
		if (iMax < iArray[i])
		{
			iMax = iArray[i];
			iCount = i + 1;
		}
	}

	cout << iMax << endl << iCount;

	return 0;
}