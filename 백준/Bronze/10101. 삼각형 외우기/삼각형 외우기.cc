#include <iostream>
using namespace std;
int main()
{
    int arr[3]; int sum = 0;
    for (int i = 0; i < 3; ++i)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    if (sum == 180)
    {
        if ((arr[0] == arr[1]) && (arr[1] == arr[2])) cout << "Equilateral";
        else if ((arr[0] == arr[1]) || (arr[1] == arr[2]) || arr[0] == arr[2]) cout << "Isosceles";
        else cout << "Scalene";
    }
    else cout << "Error";
}