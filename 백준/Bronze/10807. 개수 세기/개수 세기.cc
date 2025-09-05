#include <iostream>
using namespace std;

int main()
{
	int a = 0, c = 0, d = 0;
	int b[101];
	cin >> a;

	for (int i = 0; i < a; i++)
	{
		cin >> b[i];
	}

	cin >> c;

	for (int i = 0; i < a; i++)
	{
		if (c == b[i])
		{
			++d;
		}
	}
	cout << d;

}