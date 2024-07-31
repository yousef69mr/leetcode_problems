// find_palindromic_with_fixed_length.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

vector<long long> static kthPalindrome(vector<int>& queries, int intLength) {

	vector<long long> result(queries.size());

	if (intLength < 1) return result;

	vector<int> palindromes = {};
	string min(intLength - 1, '0'), max(intLength, '9');
	min.insert(0, "1");
	int min_range = stoi(min), max_range = stoi(max);

	//cout << min_range << max_range;
	int index, i, j, mid;
	bool isPalindrome;
	string num;

	for (index = min_range; index <= max_range; index++) {
		num = to_string(index);

		isPalindrome = true;

		mid = num.length() / 2;
		for (i = 0, j = num.length() - 1; i <= mid && mid <= j; i++, j--) {
			if (num[i] != num[j]) {
				isPalindrome = false;
			}
		}

		if (isPalindrome) {
			palindromes.emplace_back(index);
		}
	}


	for (index = 0; index < queries.size(); index++) {
		if (queries[index] > 0 && queries[index] <= palindromes.size()) {
			result[index] = palindromes[queries[index] - 1];
		}
		else {
			result[index] = -1;
		}
	}

	return result;
}

int main()
{
	vector<int> queries = { 1,2,3,4,5,90 };
	vector<int> queries_2 = { 2,201429812,8,520498110,492711727,339882032,462074369,9,7,6 };

	printVector(kthPalindrome(queries, 3));


	printVector(kthPalindrome(queries_2, 1));

	return 0;
}

