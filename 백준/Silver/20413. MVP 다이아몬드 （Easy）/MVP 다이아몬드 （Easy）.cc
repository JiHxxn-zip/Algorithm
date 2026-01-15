using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <unordered_map>
#include <climits> // INT_MAX

int  b{}, s, g, p, d, pay[36];

int cal(int idx, char C) 
{
	if (idx == 0) 
	{
		if (C == 'B')
			return s - 1;
		else if (C == 'S')
			return g - 1;
		else if (C == 'G')
			return p - 1;
		else if (C == 'P')
			return d - 1;
		else if (C == 'D')
			return d;
	}
	else 
	{
		int pPay = pay[idx - 1];

		if (C == 'B')
			return s - 1 - pPay;
		else if (C == 'S')
			return g - 1 - pPay;
		else if (C == 'G')
			return p - 1 - pPay;
		else if (C == 'P')
			return d - 1 - pPay;
		else if (C == 'D')
			return d;
	}
}

int main() 
{
	ios::sync_with_stdio(0);
	cout.tie(0);

	int N;
	cin >> N >> s >> g >> p >> d;
	
	int ans{};
	for (int i = 0; i < N; i++) 
	{
		char grd;
		cin >> grd;

		pay[i] = cal(i, grd);
		ans += pay[i];
	}

	cout << ans;

	return 0;
}