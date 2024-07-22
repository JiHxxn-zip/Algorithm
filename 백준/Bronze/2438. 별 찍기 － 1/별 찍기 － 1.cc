#include<iostream>
using namespace std;

int main()
{
    int iSelectNum(0);

    cin >> iSelectNum;

	for (int i = 0; i < iSelectNum; ++i)
	{
		for (int j = i + 1; j > 0; --j)
		{
			cout << "*";
		}
		cout << endl;
	}

    return 0;
}