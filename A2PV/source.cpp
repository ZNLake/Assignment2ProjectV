#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <string>
#include <vector>

using namespace std;

struct STUDENT_DATA
{
	string firstName;
	string lastName;
};

int main()
{
	ifstream readFile;

	vector<STUDENT_DATA> v1;
	string lineText;

	readFile.open("StudentData.txt");

	while (getline(readFile, lineText))
	{
		STUDENT_DATA student;

		int commaLocation = lineText.find(',');

		student.firstName = lineText.substr(0, commaLocation);
		student.lastName = lineText.substr(commaLocation + 1);
		v1.push_back(student);
	}

	readFile.close();
	return 1;
}