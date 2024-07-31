// gpa_calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;


const map<string, float> gradesWeights = { {"A+",4},{"A",3.7} ,{"B+",3.3} ,{"B",3} ,{"C+",2.7},{"C",2.4},{"D+",2.2},{"D",2},{"F",0} };


struct Course
{
	//string name;
	string grade;
	int creditHours;

	Course(const string& grade = "", int creditHours = 0)
		: grade(grade), creditHours(creditHours) {}

	//std::string getName() const { return name; }
	//void setName(const std::string& name) { this->name = name; }

	string getGrade() const { return grade; }
	void setGrade(const string& grade) { this->grade = grade; }

	int getCreditHours() const { return creditHours; }
	void setCreditHours(int creditHours) { this->creditHours = creditHours; }
};


float static calculateGPA(vector<Course>& courses) {

	if (courses.empty()) {
		return 0.0f;
	}

	vector<float> accumulativeGpaGrades = { 0.0f };
	vector <int> accumulativeCreditHours = { 0 };
	int index = 1;


	for (Course course : courses) {
		auto iterator = gradesWeights.find(course.getGrade());

		if (course.getGrade() != "" && iterator != gradesWeights.end()) {

			accumulativeGpaGrades.push_back(accumulativeGpaGrades[index - 1] + (course.getCreditHours() * iterator->second));
			accumulativeCreditHours.push_back(accumulativeCreditHours[index - 1] + course.getCreditHours());
			index++;
		}
	}

	if (accumulativeCreditHours[index - 1] == 0) {
		return 0.0f;
	}


	return accumulativeGpaGrades[index - 1] / accumulativeCreditHours[index - 1];

}


int main()
{
	vector<Course> courses;

	courses.emplace_back("B+", 2);
	courses.emplace_back("D", 2);
	courses.emplace_back("C+", 2);
	courses.emplace_back("C+", 3);
	courses.emplace_back("D+", 3);
	courses.emplace_back("B", 3);

	
	courses.emplace_back("C", 3);
	courses.emplace_back("C+", 3);
	courses.emplace_back("C", 3);
	courses.emplace_back("C", 3);
	courses.emplace_back("C+", 0);
	courses.emplace_back("B", 3);
	courses.emplace_back("B", 3);


	courses.emplace_back("B+", 2);
	courses.emplace_back("B", 3);
	courses.emplace_back("C", 3);
	courses.emplace_back("C+", 3);
	courses.emplace_back("B+", 3);


	courses.emplace_back("D", 3);
	courses.emplace_back("D", 3);
	courses.emplace_back("C+", 3);
	courses.emplace_back("C", 3);
	courses.emplace_back("B", 3);
	courses.emplace_back("D+", 3);


	courses.emplace_back("C+", 3);
	courses.emplace_back("D+", 3);
	courses.emplace_back("C+", 3);
	courses.emplace_back("D+", 3);
	courses.emplace_back("C+", 3);


	courses.emplace_back("B+", 3);
	courses.emplace_back("C+", 3);


	courses.emplace_back("C+", 3);
	courses.emplace_back("B+", 3);
	courses.emplace_back("A+", 6);


	courses.emplace_back("B", 3);
	courses.emplace_back("B", 3);
	courses.emplace_back("C+", 3);


	courses.emplace_back("A+", 3);
	courses.emplace_back("A", 3);
	courses.emplace_back("", 3);
	
	cout << calculateGPA(courses);

	return 0;
}
