#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <cstdio>

int main() {
#ifdef _WIN32
	freopen("input.txt", "r", stdin);
#endif // _WIN32
	long long int n;
	scanf("%lld", &n);
	
	printf("%lld\n2\n", (n - 1) * n / 2);
	return 0;
}