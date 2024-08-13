#include<iostream>
using namespace std;

int main()
{
	int iSize(0), iCount(0);
	int iInput(0), iInput2(0), iInput3(0);

	cin >> iSize >> iCount;
	int* iArray = new int[iSize] {};
	
	for (int i = 0; i < iCount; ++i)
	{
		cin >> iInput >> iInput2 >> iInput3;

		for (int j = iInput; j <= iInput2; ++j)
		{
			iArray[j - 1] = iInput3;
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