#include<iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int iSize(0), iInput(0);
    cin >> iSize;

    vector<int> vec(iSize);         // 입력 값 저장
    vector<int> vecCount(1000001);   // 등장 횟수 저장 (최대 범위 100000 가정)
    vector<int> result(iSize, -1);  // 결과 저장 (-1로 초기화)

    for (int i = 0; i < iSize; ++i) // 입력 및 등장 횟수 카운팅
    {
        cin >> vec[i];
        vecCount[vec[i]]++;
    }

    stack<int> s; // 인덱스를 저장하는 스택

    for (int i = 0; i < iSize; ++i)
    {
        // 스택에 쌓인 인덱스들 중에서 등장 횟수가 현재 값보다 적은 경우
        while (!s.empty() && vecCount[vec[s.top()]] < vecCount[vec[i]]) {
            result[s.top()] = vec[i]; // 더 큰 등장 횟수의 값으로 업데이트
            s.pop();
        }
        s.push(i); // 현재 인덱스를 스택에 추가
    }

    // 결과 출력
    for (int i = 0; i < iSize; ++i) {
        cout << result[i] << ' ';
    }

    return 0;
}