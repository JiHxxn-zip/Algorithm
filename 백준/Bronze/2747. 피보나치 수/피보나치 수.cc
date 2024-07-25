#include<iostream>
#include<map>
using namespace std;

int Fibonacci(int _iNum);

map<int, int> FiboMap;
map<int, int>::iterator p;

int main()
{
	int iSelect(0);
	cin >> iSelect;

	cout << Fibonacci(iSelect);

	return 0;
}

int Fibonacci(int _iNum)
{
	if (_iNum == 1 || _iNum == 2)
	{
		return 1;
	}

	if (FiboMap[_iNum] == false)
	{
		FiboMap[_iNum] = Fibonacci(_iNum - 1) + Fibonacci(_iNum - 2);
	}

	return FiboMap[_iNum];
}
