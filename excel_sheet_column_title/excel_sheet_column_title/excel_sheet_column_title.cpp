// excel_sheet_column_number.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <string>

using namespace std;


string convertToTitle(int columnNumber) {

	if (columnNumber <= 0) return "";



	map<int, string> columns = { {1,"A"}, {2,"B"}, {3,"C"}, {4,"D"}, {5,"E"},
	  {6,"F"}, {7,"G"}, {8,"H"}, {9,"I"}, {10,"J"},
	  {11,"K"}, {12,"L"}, {13,"M"}, {14,"N"}, {15,"O"},
	  {16,"P"}, {17,"Q"}, {18,"R"}, {19,"S"}, {20,"T"},
	  {21,"U"}, {22,"V"}, {23,"W"}, {24,"X"}, {25,"Y"},{26,"Z"} };

	string result = "";


	if (columnNumber <= 26) {
		return columns[columnNumber];
	}

	while (columnNumber > 0) {

		int remainder = (columnNumber - 1) % 26;
		result = static_cast<char>(65 + remainder) + result;  // Convert remainder to A-Z letter
		columnNumber = (columnNumber - 1) / 26;
	}

	return result;
}

int main()
{
	//cout << convertToTitle(1) << endl;
	//cout << convertToTitle(28) << endl;
	cout << convertToTitle(706) << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
