#include <iostream>
using namespace std;
int main()
{
    int num, cnt = 0, total = 0;
    cin >> num;
    int *score = new int[num];
    for (int i = 0; i < num; i++)
    {
        cin >> score[i];
    }
    for (int i = 0; i < num; i++)
    {
        if (score[i] == 1)
        {
            cnt++;
            total += cnt;
        }
        else
            cnt = 0;
    }
    cout << total << '\n';
}