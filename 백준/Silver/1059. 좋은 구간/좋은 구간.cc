#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main()
{
    int l;
    cin >> l;
 
    vector<int> vec;
    vec.resize(l);
    for (int& ele : vec) cin >> ele;
 
    // 오름차순 정렬
    sort(vec.begin(), vec.end());
 
    int n;
    cin >> n;
 
    // 집합 S에서 n보다 큰 수 중 가장 가까운 수를 찾는다.
    int s = 0, e = 0;
    for (int i = 0; i < l; i++)
    {
        if (n < vec[i])
        {
            if( i > 0) s = vec[i - 1];
            e = vec[i];
            break;
        }
    }
 
    // 만약 n보다 작은 수 중 가장 가까운 수가 n과 같다면
    // 좋은 구간은 만들 수 없다.
    if (s == n)
    {
        cout << 0;
        return 0;
    }
 
    // n을 포함하는 좋은 구간의 수를 센다.
    int cnt = 0;
    for (int i = min(s + 1, n); i <= n; i++)
    {
        for (int j = max(i + 1, n); j <= e - 1; j++)
        {
            cnt++;
        }
    }
 
    cout << cnt;
 
    return 0;
}