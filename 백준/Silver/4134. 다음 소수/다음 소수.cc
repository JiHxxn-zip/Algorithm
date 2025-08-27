#include <iostream>
#include <algorithm>
using namespace std;
bool IsPrime(long long input)
{
   long long num = input;

    if(num <= 1) return false;
    if(num == 2 || num == 3) return true;
    if(num % 2== 0 || num % 3 == 0) return false;

    for(long long i = 5; i * i <= num ;i++)
    {
        if(num % i == 0) return false;
    }

    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  
    long long N;

    cin >> N;

    for(int i = 0 ; i < N ; i++)
    {
        long long input;
        cin >> input; 


        while(!IsPrime(input))
            input++;

        cout << input << '\n';
           
    }

    return 0;
}