using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <climits> // INT_MAX

int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);

	int n;
	cin >> n;

	unordered_map<string, long long> m;

	for (int i = 0; i < n; i++)
	{
		string key;
		int value;
		cin >> key >> value;

		m[key] += value;
	}
	
	vector<long long> vec;
	for (auto& a : m)
		vec.push_back(a.second);

	sort(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); i++)
	{
		int cur = static_cast<int>(vec[i] * 1.618);
		for (int j = i+1; j < vec.size(); j++)
		{
			if (cur == vec[j])
			{
				cout << "Delicious!";
				return 0;
			}
		}
	}

	cout << "Not Delicious...";
	return 0;
}