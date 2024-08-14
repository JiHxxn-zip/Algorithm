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
		int iLoop = (iInput2 - iInput + 1) / 2;

		for (int j = 1; j <= iLoop; ++j)
		{
			swap(iArray[iInput - 1], iArray[iInput2 - 1]);

			++iInput;
			--iInput2;
		}
	}

	for (int i = 0; i < iSize; ++i)
	{
		cout << iArray[i] << " ";
	}

	delete[] iArray;
	iArray = nullptr;

	return 0;
}