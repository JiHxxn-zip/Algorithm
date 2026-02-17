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

	int t;
	cin >> t;



	while (t--)
	{
		int result{};

		int n, m, k;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];

		cin >> m;
		vector<int> b(m);
		for (int i = 0; i < m; i++)
			cin >> b[i];

		cin >> k;
		vector<int> c(k);
		for (int i = 0; i < k; i++)
			cin >> c[i];

		vector<string> results;

		// 받은 수의 조합으로 5와 8로만 이뤄진 수를 만들어야함. 3중 포문?
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				for (int l = 0; l < k; l++)
				{
					// string으로 변환 후 앞자리 뒷자리 계산?

					string answer = to_string(a[i] + b[j] + c[l]);
					bool ok{ true };

					for (int p = 0; p < answer.size(); p++)
					{
						if (answer[p] != '5' && answer[p] != '8')
							ok = false;
					}
					
					// ok 된 정답 배열에 저장
					bool chack{ true };
					if (ok)
					{
						// 결과 겹치지않게 적용
						for (int r = 0; r < results.size(); r++)
						{
							if (results[r] == answer)
								chack = false;
						}

						if (chack)
						{
							results.push_back(answer);
							result++;
						}
					}
				}
			}
		}

		cout << result << '\n';
	}

	return 0;
}