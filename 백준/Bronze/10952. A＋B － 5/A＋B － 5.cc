#include<iostream>
using namespace std;

int main()
{
	int iA(0), iB(0);

	while (true)
	{
		cin >> iA >> iB;

		if (iA == 0 && iB == 0)
		{
			return 0;
		}

		cout << iA + iB << endl;

	}

	return 0;
}