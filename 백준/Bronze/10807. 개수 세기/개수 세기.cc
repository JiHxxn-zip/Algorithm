
#include<iostream>
using namespace std;
int main()
{
	int iSelect(0), iSelect2(0), iCount(0);
	cin >> iSelect;

	int iArray[101]{};
	for (int i = 0; i < iSelect; i++)
	{
		cin >> iArray[i];
	}

	cin >> iSelect2;

	for (int i = 0; i < iSelect; i++)
	{
		iCount = iSelect2 == iArray[i] ? iCount + 1 : iCount;
	}
	
	cout << iCount;
    return 0;
 }