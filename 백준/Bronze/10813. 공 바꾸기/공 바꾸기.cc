#include<iostream>
using namespace std;

int main()
{
	int iSize(0), iCount(0);
	int iInput(0), iInput2(0), iTemp(0);

	cin >> iSize >> iCount;
	int* iArray = new int[iSize] {};

	for (int i = 0; i < iSize; ++i)
	{
		iArray[i] = i+1;
	}
	
	for (int i = 0; i < iCount; ++i)
	{
		cin >> iInput >> iInput2;

		iTemp = iArray[iInput - 1];
		iArray[iInput - 1] = iArray[iInput2 - 1];
		iArray[iInput2 - 1] = iTemp;
	}

	for (int i = 0; i < iSize; ++i)
	{
		cout << iArray[i] << " ";
	}

	delete[] iArray;
	iArray = nullptr;

	return 0;
}