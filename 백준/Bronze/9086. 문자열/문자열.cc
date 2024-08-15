#include<iostream>
using namespace std;

int main()
{
	string st("");
	int iSize(0);
	cin >> iSize;

	for (int i = 0; i < iSize; ++i)
	{
		cin >> st;
		cout << st[0] << st.at(st.size() - 1) << endl;
	}
	return 0;
}