using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include <limits>
#include <cctype> 
#include <iomanip>

typedef long long ll;

int n;
int mxAnswer{};

void AnswerChack(vector<string>& vec)
{
    // 가로
    for (int i = 0; i < n; i++)
    {
        int cnt = 1;
        for (int j = 1; j < n; j++)
        {
            if (vec[i][j] == vec[i][j - 1])
                cnt++;
            else
                cnt = 1;

            mxAnswer = max(mxAnswer, cnt);
        }
    }

    // 세로
    for (int i = 0; i < vec.size(); i++)
    {
        int cnt = 1;
        for (int j = 1; j < n; j++)
        {
            if (vec[j][i] == vec[j - 1][i])
                cnt++;
            else
                cnt = 1;

            mxAnswer = max(mxAnswer, cnt);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   
    cin >> n;

    vector<string> vec(n);;
    for (int i = 0; i < n; i++)
        cin >> vec[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < vec.size(); j++)
        {
            char tmp;
            if (j + 1 != n)
            {
                tmp = vec[i][j];
                vec[i][j] = vec[i][j + 1];
                vec[i][j + 1] = tmp;

                AnswerChack(vec);
                tmp = vec[i][j + 1];
                vec[i][j + 1] = vec[i][j];
                vec[i][j] = tmp;
            }

            if (i + 1 != n)
            {
                tmp = vec[i][j];
                vec[i][j] = vec[i + 1][j];
                vec[i + 1][j] = tmp;

                AnswerChack(vec);
                tmp = vec[i + 1][j];
                vec[i + 1][j] = vec[i][j];
                vec[i][j] = tmp;
            }

        }
    }

    cout << mxAnswer;

    return 0;
}