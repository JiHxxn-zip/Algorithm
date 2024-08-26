#include<iostream>
using namespace std;

int main()
{
	int iInput(-1), iMax(0), iRow(0), iCol(0);

	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cin >> iInput;

			if (iInput >= iMax)
			{
				iMax = iInput;
				iRow = i + 1;
				iCol = j + 1;
			}
		}
	}

	cout << iMax << ' ' << endl
		<< iRow << ' ' << iCol;
	return 0;
}