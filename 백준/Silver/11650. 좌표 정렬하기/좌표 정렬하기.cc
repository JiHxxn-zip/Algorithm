#include <iostream>
#include <algorithm>
using namespace std;

struct coordinate {
	int x;
	int y;
};

bool compare(coordinate a, coordinate b) {
	if (a.x == b.x) {			// x좌표가 같으면
		return a.y < b.y;		// b의 y좌표가 더 크도록 정렬 
	}
	else {						// x좌표가 다르면
		return a.x < b.x;		// b의 x좌표가 더 크도록 정렬 (=x좌표가 증가하는 순으로)
	}
}

int main(void) {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, tmp;
	cin >> n;

	coordinate arr[100001];

	for (int i = 0; i < n; i++) {
		cin >> arr[i].x >> arr[i].y;
	}

	sort(arr, arr + n, compare);

	for (int i = 0; i < n; i++) {
		cout << arr[i].x << " " << arr[i].y << "\n";
	}


	return 0;
}