#include<iostream>

using namespace std;

int main()
{
    float x(0.f), y(0.f);

    cin >> x;
    cin >> y;

    if (x >= 1)
    {
	    if (y >= 1)
	    {    
		    cout << "1";
	    }
	    else if(y < 0) 
	    {
		    cout << "4";
	    }
    }
    else if (x < 0)
    {
	    if (y >= 1)
	    {
		    cout << "2";
	    }
	    else if (y < 0)
	    {
		    cout << "3";
	    }
    }
    return 0;
}