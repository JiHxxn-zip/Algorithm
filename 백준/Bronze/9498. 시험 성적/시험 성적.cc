#include<iostream>
using namespace std;

int main()
{
    int iScore(0);
    
    cin >> iScore;
    
    if(90<= iScore && 100 >= iScore)
    {
        cout << "A" << endl;
    }
    else if(80 <= iScore && 90 > iScore)
    {
        cout << "B" << endl;
    }
    else if(70 <= iScore && 80 > iScore)
    {
        cout << "C" << endl;
    }
    else if(60 <= iScore && 70 > iScore)
    {
        cout << "D" << endl;
    }
    else
    {
         cout << "F" << endl;
    }
    return 0;
}