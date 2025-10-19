#include<iostream>
 
using namespace std;
 
int fivo(int N)
{
    if (N == 0) return 0;
    if (N == 1) return 1;
    return fivo(N-1)+ fivo(N-2);
}
 
int main()
{
    int N;
    cin >> N;
 
    cout << fivo(N);
}