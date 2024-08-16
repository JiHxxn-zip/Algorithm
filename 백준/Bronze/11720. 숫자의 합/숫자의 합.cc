#include<iostream>
using namespace std;

int main()
{
	int iInput(0), iSum(0);
	cin >> iInput;

	string str("");
	cin >> str;

	for (int i = 0; i < size(str); ++i)
	{
		iSum += (int)str[i] - 48;
	}
	cout << iSum;
	
	return 0;
}