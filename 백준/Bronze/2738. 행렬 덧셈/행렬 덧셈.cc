#include<iostream>
using namespace std;

int main()
{
	int row(0), col(0);
	cin >> row >> col;

	int** aArray = new int* [row] {};
	int** bArray = new int* [row] {};

	for (int i = 0; i < row; ++i)
	{
		aArray[i] = new int[col] {};
		bArray[i] = new int[col] {};
	}

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
			cin >>aArray[i][j];
	}

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
			cin >> bArray[i][j];
	}

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
			cout << aArray[i][j] + bArray[i][j] << ' ';

		cout << endl;
	}

	// 2차원 동적 배열 반환
	for (int i = 0; i < row; ++i)
	{
		delete[] aArray[i];
		delete[] bArray[i];
	}

	delete[] aArray;
	delete[] bArray;
	return 0;
}