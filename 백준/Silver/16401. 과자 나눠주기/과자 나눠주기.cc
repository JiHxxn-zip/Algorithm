using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <climits> // INT_MAX

int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);

	int m, n;
	cin >> m >> n;

	int maxSnack{};
	vector<int> vec(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
		maxSnack = max(maxSnack, vec[i]);
	}

	int left = 1, right = maxSnack;
	int cnt{}, answer{};

	while (left <= right)
	{
		// 미드를 구해야함
		int mid = left + (right - left) / 2;
		cnt = 0;

		// for문으로 vec을 순회하며 나눠준다
		for(auto& x : vec)
			cnt += x / mid;

		// 만약 m보다 cnt(나눠줄 수 있는 갯수)가 같거나 많으면
		if (m <= cnt)
		{
			answer = mid; // 현재 최대 길이 저장
			left = mid + 1; // 한번 더 최대 길이 도전
		}
		else
			right = mid - 1; // 지금 길이는 너무 커서 작게 나눠야함
	}

	cout << answer;
	return 0;
}

// 이분 탐색이 필요한 문젠데. m등분해서 갯수를 세어준다.