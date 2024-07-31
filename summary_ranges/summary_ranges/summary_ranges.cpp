// summary_ranges.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;


template <typename T>
void printVector(const std::vector<T>& vec) {
	for (const T& element : vec) {
		std::cout << element << " ";
	}
	std::cout << std::endl;
}


vector<string> static summaryRanges(vector<int>& nums) {
	vector<string> result = {};
	if (nums.empty()) return result;

	int i = 0, start = nums[0], end = -1;

	if (nums.size() == 1) {
		result.emplace_back(to_string(start));
	}
	else {
		// 0 2 3 4 6 8 9
		// 
		// 0 1 2 3 4 5 6
		while (i < nums.size()) {
			if (i == nums.size() - 1) {
				end = nums[i];

				if (start != end) {
					result.emplace_back(to_string(start).append("->").append(to_string(end)));
				}
				else {
					result.emplace_back(to_string(start));
				}
			}
			else
				if (nums[i] + 1 != nums[i + 1]) {
					end = nums[i];
					if (start != end) {
						result.emplace_back(to_string(start).append("->").append(to_string(end)));
					}
					else {
						result.emplace_back(to_string(start));
					}


					start = nums[i + 1];
					end = -1;

				}
			i++;
		}
	}


	return result;
}

int main()
{
	vector<int> nums = { 0,1,2,4,5,7 };
	printVector(summaryRanges(nums));

	vector<int> nums_2 = { 0,2,3,4,6,8,9 };
	printVector(summaryRanges(nums_2));

	return 0;
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
