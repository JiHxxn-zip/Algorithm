using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits> // INT_MAX

typedef long long ll;

// 0: 북, 1: 동, 2: 남, 3: 서
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;

		int cX{}, cY{}, cD{};
		int minX{}, maxX{}, minY{}, maxY{};

		for (int i = 0; i < s.size(); i++)
		{
			char c = s[i];

			if (c == 'L' || c == 'R')
			{
				if (c == 'L')
					cD = (cD + 3) % 4;
				else
					cD = (cD + 1) % 4;
			}
			else
			{
				if (c == 'F')
				{
					cX += dx[cD];
					cY += dy[cD];
				}
				else
				{
					cX -= dx[cD];
					cY -= dy[cD];
				}

				minX = min(minX, cX);
				maxX = max(maxX, cX);
				minY = min(minY, cY);
				maxY = max(maxY, cY);
			}
		}
		
		cout << (maxX - minX) * (maxY - minY) << '\n';
	}

	return 0;
}