#include<iostream>
using namespace std;

int main()
{
    int iSelectNum(0);

    cin >> iSelectNum;

	for (int i = 0; i < iSelectNum; ++i)
	{
		for (int j = 0; j < iSelectNum; ++j)
		{
			if (iSelectNum - 1 > i + j)
			{
				cout << " ";
			}
		}

		for (int k = 0; k < i*2+1; ++k)
		{
			cout << "*";
		}
		cout << endl;
	}

    return 0;
}