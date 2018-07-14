/*
*
*@author��Aver Jing
*@description�� Rewrite your grading program to use the conditional operator
(�� 4.7, p. 151) in place of the if�Celse statement.
*@date��July 13, 2018
*
*/

#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;

int main()
{
	vector<string> scores = { "F", "D", "C", "B", "A", "A++" };

	int grade{ 0 };
	while (cin >> grade) {
		string lettergrade = grade < 60 ? scores[0] : scores[(grade - 50) / 10];
		lettergrade +=
			(grade == 100 || grade < 60)
			? ""
			: (grade % 10 > 7) ? "+" : (grade % 10 < 3) ? "-" : "";
		cout << lettergrade << endl;
	}

	return 0;
}