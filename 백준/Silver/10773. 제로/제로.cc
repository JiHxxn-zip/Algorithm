#include<iostream>
#include <stack>
using namespace std;

int main()
{
	stack<int> st;
	int iSize(0), iInput(0), iSum(0);

	cin >> iSize;

	for (int i = 0; i < iSize; ++i)
	{
		cin >> iInput;

		if (0 == iInput)
		{
			st.pop();
			continue;
		}

		st.push(iInput);
	}

	while (!st.empty())
	{
		iSum += st.top();
		st.pop();
	}

	cout << iSum << endl;

	return 0;
}