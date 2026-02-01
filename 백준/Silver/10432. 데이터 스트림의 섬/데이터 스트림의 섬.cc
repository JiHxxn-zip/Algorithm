using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <climits> // INT_MAX

typedef long long ll;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int p;
	cin >> p;

	while (p--)
	{
		int t;
		cin >> t;
		
		int ans{};

		vector<int> vec(12);
		for (int i = 0; i < 12; i++)
			cin >> vec[i];

		for (int L = 0; L < 12; L++) 
		{
			for (int R = L + 2; R < 12; R++) 
			{
				bool chk = 1;
				int val = max(vec[L], vec[R]);
				for (int k = L + 1; k < R; k++) 
				{
					if (vec[k] <= val) 
					{
						chk = 0;
						break;
					}
				}

				if (chk) 
					ans++;
			}
		}

		cout << t << ' ' << ans << '\n';
	}

	return 0;
}