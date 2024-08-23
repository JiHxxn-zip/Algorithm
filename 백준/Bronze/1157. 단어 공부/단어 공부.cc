	#include<iostream>
	#include<map>
	#include"string"
	#include<vector>
	using namespace std;

	int main()
	{
		std::map<char, int> charCount;
		char temp('\0');
		string strName("\0");
		cin >> strName;

		for (int i = 0; i < strName.length(); ++i)
		{
			temp = (strName[i] >= 'a' && strName[i] <= 'z') ? strName[i] - 32 : strName[i];
			charCount[temp]++;
		}
	
		char result('\0');
		int iSize(0);

		for (const auto& pair : charCount)
		{
			if (pair.second > iSize)
			{
				iSize = pair.second;
				result = pair.first;
			}
			else if (pair.second == iSize)
			{	
				result = '?';
			}
		}

		cout << result;

		return 0;
	}