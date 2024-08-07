#include<iostream>
using namespace std;

int main()
{
	int iInput(0), iA(0), iMax(0), iMin(0);
	cin >> iInput;

	for (int i = 0; i < iInput; ++i)
	{
		cin >> iA;
		
		if (i == 0)
		{
			iMax = iA;
			iMin = iA;
			continue;
		}

		iMax = iA > iMax ? iA : iMax;
		iMin = iA < iMin ? iA : iMin;
	}
	cout << iMin << ' ' << iMax;

	return 0;
}