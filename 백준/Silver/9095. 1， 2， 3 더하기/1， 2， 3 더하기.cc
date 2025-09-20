#include <iostream>
#include <vector>
#include "algorithm"
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n{};
    cin >> n;
    
    while (n--)
    {
        int target;
        cin >> target;

        vector<int> vec(target + 3, 0);

        // 초기 3개의 인덱스 결과로 추론 가능하자
        vec[1] = 1;
        vec[2] = 2;
        vec[3] = 4;

        // 4부터 시작하여 미리 셋팅해놓은 1~3 값들을 모두 저장하면 해당 값이 자신의 수를 만들 수 있는 방법의 수임
        for (size_t i = 4; i <= target; i++)
        {
            vec[i] = vec[i - 1] + vec[i - 2] + vec[i - 3];
        }

        cout << vec[target] << '\n';
    }

    return 0;
}       
