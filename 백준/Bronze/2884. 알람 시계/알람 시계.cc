#include<iostream>

using namespace std;

int main()
{
    	int iHour(0), iMinute(0), iMinus(45);

	cin >> iHour;
	cin >> iMinute;

	if (iMinute < iMinus)
	{
		iMinute += 60;
		iHour = iHour == 0 ? 23 : iHour - 1;
	}
	iMinute -= iMinus;

	cout << iHour << " " << iMinute;

	
	return 0;
}