// integer_to_roman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<map>

using namespace std;

string intToRoman(int num) {
	string result = "";
	int thousands, hundreds, tenth, units;
	map<char, int> alpha = {
	{'I', 1}, {'V', 5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}
	};
	thousands = (num / 1000);
	hundreds = (num / 100 % 10);
	tenth = (num / 10 % 10);
	units = num % 10;
	// cout << thousands << endl << hundreds << endl << tenth << endl << units << endl;

	if (thousands > 0) {
		string repeated(thousands, 'M');
		result += repeated;
	}

	if (hundreds > 0) {
		if (hundreds == 9) {
			result += "CM";
		}
		else if (hundreds >= 5) {

			string repeated(hundreds - 5, 'C');
			result += 'D';
			result += repeated;
		}
		else if (hundreds == 4) {
			result += "CD";
		}
		else {
			string repeated(hundreds, 'C');
			result += repeated;
		}
	}

	if (tenth > 0) {
		if (tenth == 9) {
			result += "XC";
		}
		else if (tenth >= 5) {

			string repeated(tenth - 5, 'X');
			result += 'L';
			result += repeated;
		}
		else if (tenth == 4) {
			result += "XL";
		}
		else {
			string repeated(tenth, 'X');
			result += repeated;
		}
	}

	if (units > 0) {
		if (units == 9) {
			result += "IX";
		}
		else if (units >= 5) {

			string repeated(units - 5, 'I');
			result += 'V';
			result += repeated;
		}
		else if (units == 4) {
			result += "IV";
		}
		else {
			string repeated(units, 'I');
			result += repeated;
		}

	}

	return result;

}

int main()
{
	int num = 58;
	string result = intToRoman(num);
	cout << result;
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
