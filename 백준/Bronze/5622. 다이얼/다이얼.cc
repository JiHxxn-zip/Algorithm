#include<iostream>
using namespace std;

int main()
{
	int iTime[26] = { 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10 };
	int iSum(0);

	string str("");
	cin >> str;

	for (int i = 0; i < str.length(); ++i)
		iSum += iTime[str[i] - 'A'];

	cout << iSum;
	
	return 0;
}