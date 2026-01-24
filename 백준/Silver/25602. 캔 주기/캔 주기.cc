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

int n, k, answer{};
vector<int> A;
vector<vector<int>> R;
vector<vector<int>> M;

void DFS(int day, vector<int>& A, int sum)
{
	if (day == k)
	{
		answer = max(answer, sum);
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (A[i] == 0)
			continue;
		A[i]--;

		for (int j = 0; j < n; j++)
		{
			if (A[j] == 0)
				continue;
			A[j]--;
			DFS(day + 1, A, sum + R[day][i] + M[day][j]);
			A[j]++;
		}
		A[i]++;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);

	cin >> n >> k;

	A.assign(n, 0);
	for (int i = 0; i < n; i++)
		cin >> A[i];

	R.assign(k, vector<int>(n));
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> R[i][j];
	}

	M.assign(k, vector<int>(n));
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> M[i][j];
	}


	DFS(0,A,0);
	cout << answer;
	return 0;
}

// 캔의 종류 n가지(ex.5)
// i번쨰 캔을 A[i] 개 가지고 있음
// i번째 날 랑이가 j번째 캔을 먹었을 때 R[i][j]
// i번째 날 메리가 j번째 캔을 먹었을 때 M[i][j]
// K일 동안 랑이와 메리에게 하루에 하나의 캔을 줘서 얻을 수 있는 만족도 최대 합
