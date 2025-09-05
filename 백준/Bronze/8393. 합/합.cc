#include <iostream>
using namespace std;

int main()
{
	int a = 0, b = 1, c = 0;
	cin >> a;

	for (int i = 0; i < a; i++)
	{
		c += b;
		++b;
	}

	cout << c << "\n";
}