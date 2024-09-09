#include <iostream>
#include "stack"
using namespace std;

int main() 
{
	stack<int> st;

	string str;
	int iInput(0), iInput2(0);
	cin >> iInput;

	for (int i = 0; i < iInput; ++i)
	{
		cin >> str;
		if (str == "push")
		{
			cin >> iInput2;
			st.push(iInput2);
		}
		else if (str == "pop")
		{
			if (st.empty())
				cout << "-1\n";
			else
			{
				cout << st.top() << endl;
				st.pop();
			}

		}
		else if (str == "size")
		{
			cout << st.size() << endl;
		}
		else if (str == "empty")
		{
			if (st.empty())
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (str == "top")
		{
			if (st.empty())
				cout << "-1\n";
			else
				cout << st.top() << endl;
		}
	}
}