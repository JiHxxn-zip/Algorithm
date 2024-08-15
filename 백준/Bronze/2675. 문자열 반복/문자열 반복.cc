#include<iostream>
using namespace std;

int main()
{
	string st("");
	int iSize(0), iSize2;
	cin >> iSize;

	for (int i = 0; i < iSize; ++i)
	{
		cin >> iSize2 >> st;
		
		for (int k = 0; k < st.size(); k++)
		{
			for (int j = 0; j < iSize2; ++j)
			{
				cout << st[k];
			}
		}
		cout << endl;
	}
	return 0;
}