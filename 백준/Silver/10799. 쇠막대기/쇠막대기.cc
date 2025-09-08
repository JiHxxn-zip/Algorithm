#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
int main()
{
	/*
	괄호로 이루어진 string 변수가 있음
	이 변수만큼 반복문을 돌면서 레이저를 잘랐을 때 몇 조각까지 깨지는 지 확인하려함
	일단 나무 막대기는 stack 자료구조를 사용한다. 이유는 이전에 넣어놓았던 괄호와 매치하려면 선입 선출이 아니라 후입 선출이여야 하기 때문
	일단 첫 번째 조건으로 반복문 현재 i 번째가 '(' 이며, i + 1는 ')' 로 되어 있다면 현재까지의 조각을 나타내는 stack 사이즈 만큼 따로 카운트 변수에 저장해줌
	두 번째 조건으로는 '('만 나왔을 때 stack에 아무 숫자나 저장하여 stack의 사이즈를 하나 키워준다. 
	세 번째 조건으로는 ')'만 나왔을 때 stack에 있는 데이터를 pop해서 그냥 없애준다.
	*/

	stack<int> stack;
	string str = "";
	int cnt = 0;
	cin >> str;

	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == '(' && str[i + 1] == ')')
		{
			cnt += stack.size();
			i++;
		}
		else if (str[i] == '(')
		{
			stack.push(1);
		}
		else if (str[i] == ')')
		{
			stack.pop();
			cnt++;
		}
	}

	cout << cnt;
}