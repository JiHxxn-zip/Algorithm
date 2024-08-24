#include<iostream>
using namespace std;

int main()
{
	int iCount(0), i(0);

	string strName("\0");
	cin >> strName;


	while (i < strName.length())
	{
		if (strName[i] == 'c')
		{
			if (strName[i + 1] == '=' || strName[i + 1] == '-')
				++i;
		}
		else if (strName[i] == 'd')
		{
			if (strName[i + 1] == 'z' && strName[i + 2] == '=')
				i += 2;
			else if (strName[i + 1] == '-')
				++i;
		}
		else if (strName[i] == 'l')
		{
			if (strName[i + 1] == 'j')
				++i;
		}
		else if (strName[i] == 'n')
		{
			if (strName[i + 1] == 'j')
				++i;
		}
		else if (strName[i] == 's')
		{
			if (strName[i + 1] == '=')
				++i;
		}
		else if (strName[i] == 'z')
		{
			if (strName[i + 1] == '=')
				++i;
		}

		++i;
		++iCount;
	}
	
	cout << iCount;

	return 0;
}