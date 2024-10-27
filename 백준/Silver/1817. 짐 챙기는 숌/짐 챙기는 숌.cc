#include <iostream>

using namespace std;

int n, m;
int arr[51];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	if (n == 0) 
    {
		cout << "0" << endl;
		return 0;
	}
	for (int i = 0; i < n; i++) cin >> arr[i];
	int ans = 0;
	int now = 0;
	for (int i = 0; i < n; i++) 
    {
		if (now + arr[i] <= m) 
            now += arr[i];
		else 
        {
			ans++;
			now = arr[i];
		}
	}
	if (now != 0) ans++;
	cout << ans << endl;
}