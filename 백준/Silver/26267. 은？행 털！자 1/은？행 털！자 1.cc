using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <climits> // INT_MAX
#include <iomanip> // 소숫점 제한

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	unordered_map<ll, ll> map;
	ll answer{};
	for (int i = 0; i < n; i++)
	{
		int x, t, c;
		cin >> x >> t >> c;

		map[t - x] += c;
		answer = max(answer, map[t-x]);
	}

	cout << answer;
	return 0;
}