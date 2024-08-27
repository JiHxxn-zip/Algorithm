#include<iostream>
#include "sstream"
using namespace std;

double GetNum(string gradePoint);

int main()
{
	double iCredit(0), iGradePoint(0), iSumCredit(0), iSumCG(0); // 학점, 과목, 총 학점, 전공 평점(학점x과목)

	string str("\0"), strTemp("\0"), strCredit("\0"), strGrade("\0");

	for (int i = 0; i < 20; ++i)
	{
		getline(cin, str);

		stringstream ss(str);

		ss >> strTemp >> strCredit >> strGrade;

		if (strGrade != "P")
		{
			iCredit = stoi(strCredit);
			iGradePoint = GetNum(strGrade);

			iSumCredit += iCredit;

			if (strGrade == "F")
				continue;

			iSumCG += (iCredit * iGradePoint);
		}
	}

	cout << iSumCG / iSumCredit;
	return 0;
}

double GetNum(string gradePoint)
{
	double iNum(0);

	if (gradePoint == "A+")
		iNum = 4.5;
	else if (gradePoint =="A0")
		iNum = 4.0f;
	else if (gradePoint == ("B+"))
		iNum = 3.5f;
	else if (gradePoint == ("B0"))
		iNum = 3.0f;
	else if (gradePoint == ("C+"))
		iNum = 2.5f;
	else if (gradePoint == ("C0"))
		iNum = 2.0f;
	else if (gradePoint == ("D+"))
		iNum = 1.5f;
	else if (gradePoint == ("D0"))
		iNum = 1.0f;
	else if (gradePoint == ("F"))
		iNum = 0.f;
	else if (gradePoint == ("P"))
		iNum = 0.f;

	return iNum;
}
