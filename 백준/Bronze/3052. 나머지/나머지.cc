#include<iostream>
using namespace std;

int main()
{
	int iNum(0), iCount(0);
	int iArray[10]{ -1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
	bool bCheck(false);

	for (int i = 0; i < 10; ++i)
	{
		cin >> iNum;
		iArray[i] = iNum % 42;
	}

	for (int i = 0; i < size(iArray); ++i)
	{
		bCheck = false;
		int iTmp = iArray[i];

		for (int j = 0; j < size(iArray); ++j)
		{
			if (j > i)
				break;

			if (i != j && iArray[j] == iTmp)
			{
				bCheck = true;
			}
		}

		if (bCheck == false)
		{
			++iCount;
		}
	}

	cout << iCount << endl;

	return 0;
}