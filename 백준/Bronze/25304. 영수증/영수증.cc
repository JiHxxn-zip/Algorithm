#include <iostream>
using namespace std;

int main()
{
	int a = 0, b = 1, c = 0, d = 0;
	cin >> a;
	cin >> b;

	for (int i = 0; i < b; i++)
	{
		cin >> c >> d;
		a -= c * d;
	}

	if (a == 0)
		cout << "Yes";
	else
		cout << "No";
}