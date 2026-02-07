using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <climits> // INT_MAX
#include <deque> // INT_MAX

typedef long long ll;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	// 어떤 자료구조로.. 흠 m/n으로 시작
	// k번 반복했을 때 활성화된 원소 갯수
	// 활성화 비활성화
	// deque로 먼저 활성화 기준 양옆의 원소에게 들이댐
	// 그 원소는 자신의 양옆이 활성화 되어있는지 확인함.
	// 그리고 둘다 활성화가 되어있지 않을 경우 자신을 활성화 할것이라고 예약
	// 

	deque<char> dq(n, 0);
	for (int i = 0; i < m; i++)
	{
		int x;
		cin >> x;
		dq[x] = true;
	}

	while (k--)
	{
		deque<char> tmp(n, 0);
		for (int i = 0; i < n; i++)
		{
			bool front{ false };
			bool back{ false };
			if (i == 0)
			{
				front = dq[i + 1];
				back = dq[n - 1];
			}
			else if (i == n - 1)
			{
				front = dq[0];
				back = dq[i - 1];
			}
			else
			{
				front = dq[i + 1];
				back = dq[i - 1];
			}

			if (front && back)
				tmp[i] = false;
			else if (front)
				tmp[i] = front;
			else
				tmp[i] = back;
		}

		dq = tmp;
	}

	int result{};
	for (auto& a : dq)
		if (a)
			result++;

	cout << result;

    
	return 0;
}