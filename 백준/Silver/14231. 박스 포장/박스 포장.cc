using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <limits>
#include <iomanip> // 소숫점 제한

vector<int> vec;
vector<int> memo;

int n;

int DP(int i)
{
	int& ret = memo[i];
	if (ret != -1)
		return ret;

	ret = 1;

	for (int j = 0; j < i; j++)
		if(vec[i] > vec[j])
			ret = max(ret, DP(j)+1);

	return ret;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	vec.assign(n, 0);
	for (int i = 0; i < n; i++)
		cin >> vec[i];

	memo.assign(n, -1);

	int mx{};
	for (int i = 0; i < n; i++)
		mx = max(mx, DP(i));

	cout << mx;
	return 0;
}