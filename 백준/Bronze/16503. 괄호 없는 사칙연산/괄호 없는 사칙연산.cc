#include <iostream>
using namespace std;

int cal(int n, int m, char c) 
{
	if (c == '+')
		return n + m;
	else if (c == '-')
		return n - m;
	else if(c=='/')
		return n / m;
	else
		return n * m;
}
int main() 
{
	//계산정보 입력받기
	int n1, n2, n3;
	char c1, c2;
	cin >> n1 >> c1 >> n2 >> c2 >> n3;
 
	int result1, result2;
 
	//계산순서에 따라 결과값 저장하기
	result1 = cal(cal(n1, n2, c1), n3, c2);
	result2 = cal(n1, cal(n2, n3, c2), c1);
 
	//대소관계에 따라 출력
	if (result1 > result2)
		cout << result2 << '\n' << result1;
	else
		cout << result1 << '\n' << result2;
}