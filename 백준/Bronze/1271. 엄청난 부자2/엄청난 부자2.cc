#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> moneyArray;
vector<int> personsArray;

int moneyLength;
int personsLength;

void MakeIntArray(vector<int>& arr, string& str, int length)
{
	for (int i = 0; i < length; ++i)
	{
		arr[i] = str[i] - '0';
	}
}

void PrintQuotient(vector<int>& quotient)
{
	int size = quotient.size();

	if (size == 0) //몫이 없는 경우
	{
		cout << 0;
		return;
	}

	for (int i = 0; i < size; ++i)
	{
		cout << quotient[i];
	}
}

void PrintRemainder()
{
	int i = 0;

	while (i < moneyLength && moneyArray[i] == 0)
	{
		i++;
	}

	if (i < moneyLength) //나머지가 있는 경우
	{
		while (i < moneyLength)
		{
			cout << moneyArray[i];
			i++;
		}
	}
	else //나머지가 없는 경우
	{
		cout << 0;
	}

	cout << endl;
}

int Subtraction(int base)
{
	int index = base - personsLength + 1;
	//47664
	//46669
	//현재 base = 4, personsLength = 5로
	//index = 0 이 됩니다. 비교할 첫 시작점을 의미합니다.

	for (int i = 0; i < personsLength; ++i)
	{
		if (moneyArray[index + i] - personsArray[i] < 0) //앞에서 자리를 빌려와야됨
		{
			int j = 1;

			//47664
			//46669
			//0100 <4 - 9>
			//위 부분에서 앞자리에 빌려올 곳을 찾아야됩니다.
			while (index + i - j >= index && moneyArray[index + i - j] == 0)
			{
				j++;
			}

			if (index + i - j < index) //빌려올 곳이 시작지점을 넘어서면 못빌려옵니다.
			{
				return i; //뺄셈이 불가능하기에 빼준 앞 부분들까지 다시 더해주기 위해
						  //인덱스를 반환합니다.
			}

			moneyArray[index + i - j]--; //요기서 빌릴 수 있네요.
			j--;
			while (j > 0)
			{
				moneyArray[index + i - j] = 9; //빌려오면서 거친 부분들은 9로 만들어줍니다.
				j--;
			}
			//0100 -> 0099 가 됩니다.

			moneyArray[index + i] += 10 - personsArray[i]; //0099(14 - 9) = 00995
		}
		else //뺄셈이 가능하면 그냥 빼주기
		{
			moneyArray[index + i] -= personsArray[i];
		}
	}

	return -1; //뺄셈이 성공하면 다시 더해줄 필요가 없음
}

void Sum(int base, int limit) //뺄셈이 실패하기 - 1 지점까지 다시 더해서 복구해주기
{
	int index = base - personsLength + 1;

	for (int i = limit - 1; i >= 0; --i)
	{
		moneyArray[index + i] += personsArray[i];
	}
}

int main()
{
	string money, persons;
	vector<int> quotient;

	cin >> money >> persons;

	moneyLength = money.length();
	personsLength = persons.length();

	moneyArray.resize(moneyLength);
	personsArray.resize(personsLength);

	MakeIntArray(moneyArray, money, moneyLength);
	MakeIntArray(personsArray, persons, personsLength);

	for (int i = personsLength - 1; i < moneyLength; ++i)
	{
		//만약 1234 / 124의 경우
		//123 / 124 는 실패합니다.
		//이제 234 / 124 비교 차례인데
		//앞의 숫자(1)가 남아있는걸 갖고와주는 작업입니다.
		if (i - personsLength >= 0)
		{
			moneyArray[i - personsLength + 1] += moneyArray[i - personsLength] * 10;
			moneyArray[i - personsLength] = 0;
		}

		int div = 0; //몫

		while (true)
		{
			int failPos = Subtraction(i); //빼질때까지 계속 빼보기

			if (failPos > -1) //더이상 나눌수(뺄 수) 없으면 복구해주고 종료.
			{
				Sum(i, failPos);
				break;
			}

			div++;
		}

		if (quotient.size() == 0 && div == 0) //첫 몫이 0인지 확인
		{
			continue;
		}
		else
		{
			quotient.push_back(div);
		}
	}

	PrintQuotient(quotient);
	cout << " ";
	PrintRemainder();
}