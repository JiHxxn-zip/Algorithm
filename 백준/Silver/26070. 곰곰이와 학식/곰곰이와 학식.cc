using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <climits>
#include <cctype> 

typedef long long ll;

ll A, B, C;
ll X, Y, Z;

ll ans1, ans2, ans3;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	cin >> A >> B >> C >> X >> Y >> Z;
	{
		ll a = A, b = B, c = C, x = X, y = Y, z = Z;
		ans1 += min(a, x);
		x -= min(a, x); 

		y += x / 3;
		ans1 += min(b, y);

		y -= min(b, y); z += y / 3;
		ans1 += min(c, z);
	}
	{
		ll a = A, b = B, c = C, x = X, y = Y, z = Z;
		ans2 += min(b, y);
		y -= min(b, y); 

		z += y / 3;
		ans2 += min(c, z);

		z -= min(c, z); x += z / 3;
		ans2 += min(a, x);
	}
	{
		ll a = A, b = B, c = C, x = X, y = Y, z = Z;
		ans3 += min(c, z);
		z -= min(c, z); 

		x += z / 3;
		ans3 += min(a, x);

		x -= min(a, x); y += x / 3;
		ans3 += min(b, y);
	}

	cout << max(ans1, max(ans2, ans3));
    return 0;
}
