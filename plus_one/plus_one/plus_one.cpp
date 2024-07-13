// plus_one.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

void printVector(const std::vector<int>& vec) {
	for (size_t i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}


vector<int> plusOne(vector<int>& digits) {

	int n = digits.size();
	if (n == 0) {
		vector<int> result = { 1 };
		return result;
	}

	if (digits[n - 1] < 9) {
		digits[n - 1]++;
		return digits;
	}

	for (int i = n - 1; i >= 0; i--) {
		if (digits[i] == 9) {
			digits[i] = 0;
			if (i != 0) {
				if (digits[i - 1] != 9) {
					digits[i - 1]++;
					break;
				}

			}
			else {
				digits.insert(digits.begin(), 1);
			}
		}
	}



	return digits;
}
int main()
{
	vector<int> digits = { 9,9 };
	printVector(plusOne(digits));
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
