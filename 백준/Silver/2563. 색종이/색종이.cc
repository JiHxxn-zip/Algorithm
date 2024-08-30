#include<iostream>
using namespace std;

int main()
{
    int iArray[100][100]{};
    int iNum(0), iA(0), iB(0), iAnswer(0);

    cin >> iNum;
    for (int i = 0; i < iNum; ++i)
    {
        cin >> iA >> iB;

        for (int j = iA; j < iA + 10; ++j)
        {
            for (int k = iB; k < iB + 10; ++k)
            {
                iArray[j][k] = 1;
            }
        }
    }

    for (int i = 0; i < 100; ++i)
    {
        for (int j = 0; j < 100; ++j)
        {
            if (1 == iArray[i][j])
                ++iAnswer;
        }
    }

    cout << iAnswer;

    return 0;
}
