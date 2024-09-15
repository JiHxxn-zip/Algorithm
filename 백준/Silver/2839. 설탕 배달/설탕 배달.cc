#include <iostream>
using namespace std;

int main() 
{
	int n(0), iAnswer(0);
	cin >> n;

	while (n >= 0) 
	{
		if (n % 5 == 0) // 5kg 봉지로 나누어 떨어지면
		{	
			iAnswer += (n / 5);	// 5kg 봉지로 나눈 몫을 더함
			cout << iAnswer << endl;
			return 0;
		}

		n -= 3;	// 3kg 봉지로 나누고 
		iAnswer++;	// 가방 하나 추가
	}

	cout << -1 << endl;
}