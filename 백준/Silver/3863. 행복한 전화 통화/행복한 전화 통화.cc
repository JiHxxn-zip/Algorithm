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

	int n, m;		// 통화의 수 n, 구간의 수 m

	while (true)
	{
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;

		vector<pair<int, int>> vec(n);

		for (int i = 0; i < n; i++)
		{
			int a, aa, start, duration;
			cin >> a >> aa >> start >> duration;

			vec[i] = {start, duration};
		}

		for (int i = 0; i < m; i++)
		{
			int result{};
			int start, duration;
			cin >> start >> duration;
			
			int listenEnd = start + duration;

			for (int j = 0; j < n; j++)
			{
				int callStart = vec[j].first;
				int callEnd = callStart + vec[j].second;

				if (callStart < listenEnd &&
					start < callEnd)
					result++;
			}

			cout << result << '\n';
		}
	}

	return 0;
}