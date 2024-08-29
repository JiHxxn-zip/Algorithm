#include<iostream>
using namespace std;

int main()
{
	int iSize(0), iInput(0);
	int iArray[4]{25, 10, 5, 1};

	cin >> iSize;
	for (int i = 0; i < iSize; ++i)
	{
		cin >> iInput;

		for (int j = 0; j < 4; ++j)
		{
			cout << iInput / iArray[j] <<' ';
			iInput %= iArray[j];
		}
		cout << endl;
	}
	
	return 0;
}
