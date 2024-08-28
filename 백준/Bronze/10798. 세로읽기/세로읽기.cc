#include<iostream>
using namespace std;

int main()
{
	char szArray[5][15]{};

	for (int i = 0; i < 5; ++i)
		cin >> szArray[i];

	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (szArray[j][i] == NULL)
				continue;

			cout << szArray[j][i];
		}
	}
	
	return 0;
}
