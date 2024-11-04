#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string a, b;
	cin >> a >> b;
	int ans = b.size();
	int len = b.size() - a.size();
	for (int i = 0; i <= len; i++)
	{
		int cnt = 0;
		for (int j = 0; j < a.size(); j++)
		{
			if (a[j] != b[i + j])
				cnt++;
		}
		ans = min(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}