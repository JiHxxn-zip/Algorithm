using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <limits>
#include <cctype> 
#include <iomanip>

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];

    // 슬라이딩 윈도우
    int sum{};

    int startIndex{};
    for (int i = 0; i < n; i++)
    {
        sum += vec[i];
        startIndex++;

        if (k <= sum)
            break;
    }

    int answer{ sum - k};
    int changeIdx{startIndex};
    for (int i = startIndex; i < n; i++)
    {
        if (sum < k)
        {
            sum += vec[i];
            changeIdx++;

            if (i + 1 == n)
            {
                answer += sum - k;
            }
            continue;
        }
        
        int tmpSum = sum - vec[i - changeIdx];
        tmpSum += vec[i];
        if (sum < tmpSum)
        {
            answer -= sum - k;
            sum = tmpSum;
            answer += sum - k;

            sum = 0;
            changeIdx = 0;
        }
        else if(i+1 < n)
        {
            if (sum < tmpSum + vec[i + 1])
            {
                answer -= sum - k;
                sum = tmpSum + vec[i + 1];
                answer += sum - k;

                sum = 0;
                changeIdx = 0;
                i++;
            }
        }

    }

    cout << answer;

    return 0;
}