using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <climits>
#include <cctype> 
#include <iomanip>

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
	
    priority_queue<float, vector<float>, greater<float>> pq;
    for (int i = 0; i < n; i++)
    {
        float a;
        cin >> a;
        pq.push(a);
    }

    int count = 7;
    while (count > 0)
    {
        cout << fixed << setprecision(3) << pq.top() << '\n';
        pq.pop();
        count--;
    }

    return 0;
}
