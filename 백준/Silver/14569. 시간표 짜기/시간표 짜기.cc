using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>

int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<queue<int>> vec(n, queue<int>());
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		for (int j = 0; j < k; j++)
		{
			int t;
			cin >> t;
			vec[i].push(t);
		}
	}

	int m;
	cin >> m;

	vector<vector<int>> vec2(m, vector<int>());
	for (int i = 0; i < m; i++)
	{
		int p;
		cin >> p;

		for (int j = 0; j < p; j++)
		{
			int q;
			cin >> q;
			vec2[i].push_back(q);
		}
	}

	for (int i = 0; i < m; i++)
	{
		unordered_set<int> taken(vec2[i].begin(), vec2[i].end());
		int result{};

		for (int j = 0; j < n; j++)
		{
			bool ok{ true };
			auto q = vec[j];

			while (!q.empty())
			{
				if (taken.find(q.front()) == taken.end())
				{
					ok = false;
					break;
				}
				q.pop();
			}
			
			if (ok)
				result++;
		}

		cout << result << '\n';
	}

	return 0;
}

/* m번만큼 돌되
n번을 또 순회하며 복사본 queue를 만들고
vec2[] 를 순회하며 queue가 emfpy가 되면 카운트 1 증가*/