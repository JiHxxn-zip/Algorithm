#include<iostream>

using namespace std;

int main() 
{
	int result=2;

	int repeat;
	cin >> repeat;

	while (repeat--) result = (result * 2) - 1;

	cout << result * result;
}