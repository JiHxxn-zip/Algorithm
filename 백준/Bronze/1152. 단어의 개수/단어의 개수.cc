#include<iostream>
#include"string"
using namespace std;

int main()
{
	int iSum(0);
	bool bCheck(true);

	string str("");
	getline(cin, str);

	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] == ' ')
		{
			bCheck = true;
			continue;
		}

		if(str[i] != ' ' && bCheck)
		{
			++iSum;
			bCheck = false;
		}
	}
	cout << iSum;
	
	return 0;
}