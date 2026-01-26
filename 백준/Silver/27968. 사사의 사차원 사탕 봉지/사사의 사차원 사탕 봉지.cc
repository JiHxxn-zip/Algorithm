using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <climits> // INT_MAX

typedef long long ll;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<ll> candy_Count(m);
	vector<ll> psum(m+1);
	
	for (int i = 1; i <= m; i++)
	{
		cin >> candy_Count[i-1];
		psum[i] = psum[i - 1] + candy_Count[i-1];
	}

	for (int i = 0; i < n; i++)
	{
		ll curC{};
		cin >> curC;

		auto it = lower_bound(psum.begin(), psum.end(), curC);

		if (it != psum.end())
			cout << (it - psum.begin()) << '\n'; 
		else
			cout << "Go away!\n";
	}

	return 0;
}

// 자료구조, 그래프 탐색, 그리디/DP/백트래킹, 
// LIS, 그래프, 구현, 이분탐색, 문자열, 비트마스크, 누적합