#include <iostream>
#include <algorithm>
using namespace std;

int cmp(string a, string b) 
{
	if (a.length() == b.length())
		return a < b;
	else 
		return a.length() < b.length();
}

// 범위가 크기때문에 전역변수로 설정
string word[20000];

int main() 
{
	int N;

	cin >> N;
	for (int i = 0; i < N; i++) 
		cin >> word[i];

	sort(word, word + N, cmp);

	for (int i = 0; i < N; i++) 
    {
		// 중복된 경우 한번만 출력
		if (word[i] == word[i - 1])
			continue;
		
		cout << word[i] << "\n";
	}

	return 0;
}