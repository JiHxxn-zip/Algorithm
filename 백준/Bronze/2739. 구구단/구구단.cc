#include<iostream>
using namespace std;

int main()
{
    int iInput(0);
cin >> iInput;

for (int i = 1; i <= 9; ++i)
{
    cout << iInput << " * " << i << " = " <<iInput * i << endl;
}
    return 0;
}