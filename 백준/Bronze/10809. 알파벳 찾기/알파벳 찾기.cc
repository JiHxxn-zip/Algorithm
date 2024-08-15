#include<iostream>
using namespace std;

int main()
{
	string str = "";
	bool isCheck(false);

	cin >> str;

	for (int i = 97; i <= 122; ++i)
	{
		isCheck = false;

		for (int j = 0; j < size(str); ++j)
		{
			if (str[j] == (char(i)))
			{
				cout << j << ' ';
				isCheck = true;
				break;
			}
		}

		if (isCheck == false)
			cout << "-1" << ' ';
	}
	
	return 0;
}