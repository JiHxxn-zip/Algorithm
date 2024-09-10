#include <iostream>
#include<list>
using namespace std;

int main() 
{
	list<char> cList;
	int iInput(0);
	string str;
	list<char>::iterator iter;

	cin >> str;

	for (int i = 0; i < str.size(); ++i)
		cList.push_back(str[i]);

	iter = cList.end();

	cin >> iInput;
	for (int i = 0; i < iInput; ++i)
	{
		cin >> str;

		if (str == "L")
		{
			if (iter != cList.begin())
			{
				iter--;
			}
		}
		else if (str == "D")
		{
			if (iter != cList.end())
			{
				iter++;
			}
		}
		else if (str == "B")
		{
			if (iter != cList.begin())
			{
				iter--;
				iter = cList.erase(iter);
			}
		}
		else if (str == "P")
		{
			cin >> str;

			iter = cList.insert(iter, str[0]);

			iter++;
		}
	}

	iter = cList.begin();

	for (; iter != cList.end(); ++iter)
		cout << (*iter);

	return 0;
}