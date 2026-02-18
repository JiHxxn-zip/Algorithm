using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, x;
	cin >> n >> x;

	vector<int> vec(n); 
	for (int i = 0; i < n; i++) 
	{ 
		int y; 
		cin >> y; 
		if (i == 0) 
			vec[i] = y; 
		else 
			vec[i] = y + vec[i - 1]; 
	}

	int answer{}, sum{}, count{1};
	for (int i = 0; i <= n - x; i++)
	{
		if (i == 0)
			sum = vec[x - 1];
		else
			sum = vec[i + x - 1] - vec[i - 1];		
		
		if (sum == answer)
			count++;
		else if(sum > answer)
		{
			answer = sum;
			count = 1;
		}
	}

	if (answer == 0)
		cout << "SAD";
	else
		cout << answer << '\n' << count;

	return 0;
}