using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
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

	vector<int> vec(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i];

	sort(vec.begin(), vec.end());

	int answer{};
	answer = INT_MAX;

	for (auto st : vec)
	{ 
		int count{};

		for (int i = 0; i < 5; i++)
		{
			if (find(vec.begin(), vec.end(), st + i) != vec.end())
				count++;
		}

		answer = min(answer,  5 - count);
	}

	cout << answer;
	return 0;
}

