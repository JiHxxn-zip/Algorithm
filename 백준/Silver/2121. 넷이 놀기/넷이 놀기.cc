using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <limits>
#include <iomanip> // 소숫점 제한


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n;
    cin >> n;

    int A, B;
    cin >> A >> B;

    vector<pair<int,int>> points(n);
    set<pair<int, int>> s;

    for (int i = 0; i < n; i++) 
    {
        cin >> points[i].first >> points[i].second;
        s.insert(points[i]);
    }

    int count{};

    for (int i = 0; i < n; i++) 
    {
        int x = points[i].first;
        int y = points[i].second;

        if (s.find({ x + A, y }) != s.end() &&
            s.find({ x, y + B }) != s.end() &&
            s.find({ x + A, y + B }) != s.end()) 
        {
            count++;
        }
    }

    cout << count;
	return 0;
}