#include<iostream>
using namespace std;

int main()
{
    int iSelectNum(0), iCount;

    cin >> iSelectNum;
	iCount = iSelectNum * 2 - 1;

	for (int i = 0; i < iSelectNum; ++i)
	{
		for (int j = 0; j < iSelectNum; ++j)
		{
			if (i > j)
			{
				cout << " ";
			}
		}

		for (int k = 0; k < iCount; ++k)
		{
			cout << "*";
		}
		iCount -= 2;
		cout << endl;
	}

    return 0;
}
