#include <iostream>
using namespace std;
int main()
{
    int arr[3]; bool flag[3] = { false };
    int max = 0; int idx; int sum = 0;
    while (true)
    {
        for (int i = 0; i < 3; ++i)
        {
            cin >> arr[i];
            if (arr[i] > i) { max = arr[i]; idx = i; } //제일 긴 변과 해당 인덱스 저장
        }
        if ((arr[0] == 0) && (arr[1] == 0) && (arr[2] == 0)) exit(0);
        flag[idx] = true; //제일 긴 변의 인덱스의 플래그를 true로 표시
        for (int i = 0; i < 3; ++i)
        {
            if (flag[i] == true) 
                continue; //플래그 i번째 인덱스가 true면 패스
            else 
                sum += arr[i]; //나머지 인덱스(제일 긴 변이 아닌 애들)를 모두 더함
        }
        if (arr[idx] >= sum) { cout << "Invalid" << endl; } //가장 긴 변이 나머지 두 변을 더한 값보다 크거나 같으면 삼각형이 아님
        else if((arr[0] == arr[1]) && (arr[1] == arr[2])) { cout << "Equilateral" << endl; } //세 변의 길이가 모두 같을 때
        else if((arr[0] == arr[1]) || (arr[1] == arr[2]) || (arr[0] == arr[2])) { cout << "Isosceles" << endl; } //두 변의 길이가 같을 때
        else { cout << "Scalene" << endl; } //변의 길이가 모두 다를 때
        flag[idx] = false; max = 0; sum = 0; //다음 입력을 위해 초기화
    }
}