#include<iostream>
using namespace std;

int main()
{
	int iDefault[6] = {1, 1, 2, 2, 2, 8};
	int iArray[6] = {};

	cin >> iArray[0] >> iArray[1] >> iArray[2] >> iArray[3] >> iArray[4] >> iArray[5];

	for (int i = 0; i < 6; ++i)
	{
		iArray[i] = iDefault[i] - iArray[i];
		cout << iArray[i] << ' ';
	}
	
	return 0;
}