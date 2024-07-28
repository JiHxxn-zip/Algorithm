#include<iostream>
using namespace std;

int main()
{
	int iSelect(0), iSelect2(0);
	cin >> iSelect >> iSelect2;;

	int iArray[10000]{};
	for (int i = 0; i < iSelect; i++)
	{
		cin >> iArray[i];
	}

	for (int i = 0; i < iSelect; i++)
	{
		if (iArray[i] < iSelect2)
			cout << iArray[i] << " ";
	}
	return 0;
}