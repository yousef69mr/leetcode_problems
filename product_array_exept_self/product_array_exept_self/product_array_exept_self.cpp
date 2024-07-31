// product_array_exept_self.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;


template <typename T>
void printVector(const std::vector<T>& vec) {
	for (const T& element : vec) {
		std::cout << element << " ";
	}
	std::cout << std::endl;
}

vector<int> static productExceptSelf(vector<int>& nums) {
	vector<int> answer(nums.size());


	return answer;
}

int main()
{
	vector<int> nums = { 1,2,3,4 };
	vector<int> nums_2 = { -1,1,0,-3,3 };
	printVector(productExceptSelf(nums));
	printVector(productExceptSelf(nums_2));
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
