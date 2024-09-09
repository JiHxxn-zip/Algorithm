#include <iostream>
using namespace std;

int main() 
{
	int iInput(0), i(1);
	cin >> iInput;
	
	while (iInput > i) 
	{
		iInput -= i;
		i++;
	}

	if (i % 2 == 1)
		cout << i + 1 - iInput << '/' << iInput << endl;
	else
		cout << iInput << '/' << i + 1 - iInput << endl;
}