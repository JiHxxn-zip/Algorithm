#include<iostream>
using namespace std;

int main()
{
	int iArray[30]{};
	int iA(0);

	for (int i = 0; i < 28; ++i)
	{
		cin >> iA;
		iArray[iA-1] = 1;
	}

	for (int i = 0; i < size(iArray); ++i)
	{
		if (iArray[i] == false)
		{
			cout << i + 1 << endl;
		}
	}

	return 0;
}