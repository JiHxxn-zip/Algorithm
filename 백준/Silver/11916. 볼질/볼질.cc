using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
#include <cctype> 
#include <iomanip>

typedef long long ll;

vector<int> vec;
int result;
int ballCount{};

void Cal(int type) // 1 폭투
{
    if (type == 0) // 볼넷 / 몸맞공
    {
        if (vec[0]) // 1루 주자가 있어야 2루가 밀림
        {
            if (vec[1]) // 2루 주자가 있어야 3루가 밀림
            {
                if (vec[2]) // 3루 주자가 있어야 홈으로 밀림
                    result++;
                vec[2] = 1;
            }
            vec[1] = 1;
        }
        vec[0] = 1; // 타자 1루
    }
    else // 폭투
    {
        if (vec[2]) result++;
        vec[2] = vec[1];
        vec[1] = vec[0];
        vec[0] = 0;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;


    vec.assign(3, 0);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        if (x == 1) // 1 볼
        {
            ballCount++;
        }
        else if (x == 2) // 2 몸맞공
        {
            Cal(0);
            ballCount = 0;
        }
        else  // 2 폭투
        {
            Cal(1);
            ballCount++;
        }

        if (ballCount == 4)
        {
            Cal(0);
            ballCount = 0;
        }
    }

    cout << result;
    return 0;
}
