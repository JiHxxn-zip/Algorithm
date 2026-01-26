using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <climits> // INT_MAX

typedef long long ll;

ll memo[36];

ll DP(int x)
{
	if (x == 0)
		return 1;

	ll& ret = memo[x];
	if (ret != -1)
		return ret;

	ret = 0;
	for (int i = 0; i < x; i++)
		ret += DP(i) * DP(x - i - 1);

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	fill(begin(memo), end(memo), -1LL);

	cout << DP(n);
	return 0;
}
