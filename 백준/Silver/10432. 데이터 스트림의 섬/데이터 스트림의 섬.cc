using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits>
#include <cctype> 
#include <iomanip>

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	int p;
	cin >> p;

	while (p--)
	{
		int p;
		cin >> p;

		vector<int> vec(12);
		for (int i = 0; i < 12; i++)
			cin >> vec[i];

		int answer{};
		for (int L = 0; L < 12; L++)
		{
			for (int R = L+2; R < 12; R++)
			{
				int mx = max(vec[L], vec[R]);

				bool check = false;
				for (int k = L+1; k < R; k++)
				{
					if (vec[k] <= mx)
					{
						check = true;
						break;
					}
				}

				if (!check)
					answer++;
			}
		}

		cout << p << ' ' << answer << '\n';
	}

    return 0;
}

// 결국은 l과 r을 뽑아서 가운데 숫자들이 클 경우