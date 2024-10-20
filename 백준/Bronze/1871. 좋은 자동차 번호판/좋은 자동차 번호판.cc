#include <iostream>
#include <string>
#include <math.h>
 
using namespace std;
 
int main()
{
    int n;
    string word;
    cin >> n;
 
    for (int i = 0; i < n; i++) 
    {
        int c1 = 0, c2 = 0;
        cin >> word;
 
        for (int j = 0; j < 3; j++) 
        {
            // math.h 의 pow 함수
            c1 += int(word[j] - 'A') * pow(26, 2 - j);
        }
 
        c2 = stoi(word.substr(4, 4));
 
        // 절댓값을 구하는 math.h의 abs()
        if (abs(c1 - c2) <= 100) 
            cout << "nice\n";
        else 
            cout << "not nice\n";
    }
 
    return 0;
}