#include<iostream>
#include"string"
using namespace std;

int main()
{
	int iNum(0), iNum2(0), iResult(0);
	bool bSelect(false);

	string str(""), sTemp("");
	getline(cin, str);

	for (int i = str.length()-1; i >= 0; --i)
	{
		if (str[i] == ' ')
		{
			bSelect = true;
			iNum = stoi(sTemp);
			sTemp = "";
			continue;
		}

		sTemp += str[i];
	}

	iNum2 = stoi(sTemp);

	iResult = iNum > iNum2 ? iNum : iNum2;
	cout << iResult;
	
	return 0;
}