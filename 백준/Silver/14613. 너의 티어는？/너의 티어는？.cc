using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <climits> // INT_MAX
#include <iomanip>

using ll = long long;

double w, l, d;
double memo[21][2001];
bool vis[21][2001];

double DP(int game, int diff)
{
	if (diff < -1000 || diff > 1000) 
		return 0.0;

	if (game == 0)
		return (diff == 0 ? 1.0 : 0.0);

	int idx = diff + 1000;

	if (vis[game][idx])
		return memo[game][idx];

	vis[game][idx] = true;

	double& ret = memo[game][idx];
	ret = 0.0;

	ret += DP(game - 1, diff - 50) * w; // 승
	ret += DP(game - 1, diff + 50) * l; // 패
	ret += DP(game - 1, diff) * d;      // 무
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> w >> l >> d;

	double bronze{}, silver{}, gold{}, plat{}, dia{};

	for (int diff = -1000; diff <= 1000; diff++)
	{
		double p = DP(20, diff);
		int score = 2000 + diff;

		if (1000 <= score && score <= 1499) 
			bronze += p;
		else if (1500 <= score && score <= 1999) 
			silver += p;
		else if (2000 <= score && score <= 2499) 
			gold += p;
		else if (2500 <= score && score <= 2999) 
			plat += p;
		else if (3000 <= score && score <= 3499) 
			dia += p;
	}

	cout << fixed << setprecision(8);
	cout << bronze << "\n" << silver << "\n" << gold << "\n"
		<< plat << "\n" << dia;

	return 0;
}