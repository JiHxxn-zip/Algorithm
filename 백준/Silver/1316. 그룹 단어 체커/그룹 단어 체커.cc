#include<iostream>
#include "map"
using namespace std;

int main()
{
	map<char, int> map;
	char prevChar('\0');
	string str;

	int iLoop(0), iCount(0);
	cin >> iLoop;

	for (int i = 0; i < iLoop; ++i)
	{
		++iCount;
		prevChar = '\0';
		map.clear();
		cin >> str;
		for (int j = 0; j < str.length(); ++j)
		{
			if (j == 0)
			{
				prevChar = str[j];
				map[prevChar]++;
				continue;
			}

			if (str[j] != prevChar)
			{
				if (map.find(str[j]) != map.end())
				{
					--iCount;
					break;
				}
			}

			prevChar = str[j];
			map[prevChar]++;
		}
	}

	cout << iCount;

	return 0;
}