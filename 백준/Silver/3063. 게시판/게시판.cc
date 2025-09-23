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
        int x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

        // 첫 번째 공고 크기 = (x2 - x1) * (y2 - y1)
        int answer = (x2 - x1) * (y2 - y1) - max((min(x2, x4) - max(x1, x3)), 0) * max((min(y2, y4) - max(y1, y3)), 0);
        cout << answer << '\n';
    }

    return 0;
}       

// 첫번 째 공고의 보여지는 넓이 구하기
// 위에 덮혀진 공고가 있으니 겹치는 부분의 크기를 구해서 첫번 째 공고 넓이에서 빼주면 됨.
