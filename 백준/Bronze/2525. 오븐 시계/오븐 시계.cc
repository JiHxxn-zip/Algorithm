#include<iostream>
using namespace std;

int main()
{
    int iHour(0), iMinet(0), iPlus(0);
    bool bCheck(false), bCheck2(false);
    cin >> iHour >> iMinet;
    cin >> iPlus;
    iMinet += iPlus;

    while (true)
    {
        if (60 <= iMinet)
        {
            iMinet -= 60;
            ++iHour;
        }
        else 
            bCheck = true;

        if (24 <= iHour)
            iHour = 0;
        else
            bCheck2 = true;

        if (bCheck && bCheck2)
            break;
    }

    std::cout << iHour << " " << iMinet;

    return 0;
}