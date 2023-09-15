#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <string>
#include <vector>

#ifdef _DEBUG
#define LOG(x) std::cout << "MACRO: " << x << endl;
//#define PRE_RELEASE
#define MAIN
#else
#define LOG(x)
#endif // _DEBUG

using namespace std;

struct STUDENT_DATA
{
	string firstName;
	string lastName;

#ifdef PRE_RELEASE
	string email;
#endif
};

int main()
{
	ifstream readFile;

	vector<STUDENT_DATA> v1;
	string lineText;

#ifdef MAIN
	LOG("running standard code.")
		readFile.open("StudentData.txt");
#endif

#ifdef PRE_RELEASE
	LOG("running PreRelease code.")
		readFile.open("StudentData_Emails.txt");
#endif

	while (getline(readFile, lineText))
	{
		STUDENT_DATA student;

		int commaLocation = lineText.find_first_of(',');
		student.firstName = lineText.substr(0, commaLocation);

#ifdef MAIN
		student.lastName = lineText.substr(commaLocation + 1);
#endif

#ifdef PRE_RELEASE
		int commaLocation2 = lineText.find_last_of(',');
		student.lastName = lineText.substr(commaLocation + 1, commaLocation2);
		student.email = lineText.substr(commaLocation2 + 1);
#endif
		v1.push_back(student);

#ifdef MAIN
		cout << v1.back().lastName + ", " + v1.back().firstName << endl;
#endif

#ifdef PRE_RELEASE
		cout << v1.back().lastName + ", " + v1.back().firstName + ", " + v1.back().email << endl;
#endif
	}

	readFile.close();

	return 1;
}