#include <iostream>
#include<queue>
using namespace std;

int main() 
{
	queue<int> q;
	int iSize(0), iInput(0);
	string str;

	cin >> iSize;
	for (int i = 0; i < iSize; ++i)
	{
		cin >> str;

		if (str == "push")
		{
			cin >> iInput;
			q.push(iInput);
		}
		else if (str == "pop")
		{
			if (q.empty())
				cout << "-1\n";
			else
			{
				cout << q.front() << endl;
				q.pop();
			}

		}
		else if (str == "size")
		{
			cout << q.size() << endl;
		}
		else if (str == "empty")
		{
			if (q.empty())
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (str == "front")
		{
			if (q.empty())
				cout << "-1\n";
			else
				cout << q.front() << endl;
		}
		else if (str == "back")
		{
			if (q.empty())
				cout << "-1\n";
			else
				cout << q.back() << endl;
		}
	}

	return 0;
}