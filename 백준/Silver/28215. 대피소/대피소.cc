using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits> // INT_MAX

int n, k;
vector<int> x, y;

int calc(int i, int j, int k)
{
	int result{};
	for (int h = 0; h < n; h++)
	{
		result = max(result, 
			min(min(abs(x[i] - x[h]) + abs(y[i] - y[h]), abs(x[j] - x[h]) + abs(y[j] - y[h])), 
				abs(x[k] - x[h]) + abs(y[k] - y[h])));
	}
	return result;
}
int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);

	cin >> n >> k;
	x.assign(n, 0);
	y.assign(n, 0);

	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	
	int answer = 1e9;
	if (k == 1)
	{
		for (int i = 0; i < n; i++)
			answer = min(answer, calc(i, i, i));
	}
	else if (k == 2)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				answer = min(answer, calc(i, j, j));
	}
	else
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int k = 0; k < n; k++)
					answer = min(answer, calc(i, j, k));
	}

	cout << answer;
	return 0;
}