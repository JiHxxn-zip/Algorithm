	#include <iostream>
	using namespace std;

	int main() 
	{
		int n(0), m(0), iResult(0);
		int* iArray;
		cin >> n >> m;
		iArray = new int[n];

		for (int i = 0; i < n; ++i)
			cin >> iArray[i];


		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				for (int k = 0; k < n; k++)
				{
					int iSum(0);
					if(i != j && i != k && j!= k)
						iSum = iArray[i] + iArray[j] + iArray[k];

					if (m >= iSum && iResult < iSum)
						iResult = iSum;
				}
			}
		}

		cout << iResult;

		delete[] iArray;
		return 0;
	}