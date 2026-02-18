using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits> // INT_MAX
#include <iomanip> // 소숫점 제한

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, x;
	cin >> n >> x;

	vector<int> vec(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i];

	int sum{};
	for (int i = 0; i < x; i++)
		sum += vec[i];

	int maxSum{sum};
	int count{1};

	// 슬라이딩 윈도우
	for (int i = x; i < n; i++)
	{
		sum += vec[i];
		sum -= vec[i - x];

		if (sum == maxSum)
			count++;
		else if (sum > maxSum)
		{
			maxSum = sum;
			count = 1;   
		}
	}

	if (maxSum == 0)
		cout << "SAD";
	else
		cout << maxSum << '\n' << count;
	return 0;
}