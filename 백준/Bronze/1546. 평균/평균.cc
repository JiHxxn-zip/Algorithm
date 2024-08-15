#include<iostream>
using namespace std;

int main()
{
	int iSize(0);
	float iInput(0.f), iSum(0.f), iMax(0.f);
	double dResult(0);

	cin >> iSize;
	int* iArray = new int[iSize] {};

	for (int i = 0; i < iSize; ++i)
	{
		cin >> iInput;
		iArray[i] = iInput;
		iSum += iInput;

		if (i == 0)
		{
			iMax = iInput;
			continue;
		}

		iMax = iInput > iMax ? iInput : iMax;
	}
	
	dResult = iSum / iMax  * 100 / iSize;
	cout << dResult << endl;

	return 0;
}