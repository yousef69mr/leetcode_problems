// merge_overlap_intervals.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

template <typename T>
void printVector(const std::vector<T>& vec) {
	for (const T& element : vec) {
		std::cout << element << " ";
	}
	std::cout << std::endl;
}

template <typename T>
void printMatrix(const vector<vector<T>>& matrix) {
	for (const auto& row : matrix) {
		printVector(row);

	}
	cout << "##################\n";
}

bool compareRows(const vector<int>& a, const vector<int>& b) {
	return a[0] < b[0];
}

vector<vector<int>> static merge(vector<vector<int>>& intervals) {
	vector<vector<int>> result = {};
	if (intervals.empty()) return result;

	// sort interval based on start
	sort(intervals.begin(), intervals.end(), compareRows);

	//printMatrix(intervals);
	vector<int> interval = intervals[0];
	int start = interval[0];
	int end = interval[1];


	for (int i = 1; i < intervals.size(); i++) {

		if (intervals[i][0] <= interval[1]) {
			interval[1] = max(interval[1], intervals[i][1]);
		}
		else {
			result.push_back(interval);
			interval = intervals[i];
		}

	}


	result.emplace_back(interval);



	return result;
}

int main()
{
	vector<vector<int>> intervals = { { 1,3 }, { 2,6 }, { 8,10 }, { 15,18 } };
	printMatrix(merge(intervals));

	vector<vector<int>> intervals_2 = { { 1,4 }, { 4,5 } };
	printMatrix(merge(intervals_2));

	vector<vector<int>> intervals_3 = { { 1,4 }, { 2,3 } };
	printMatrix(merge(intervals_3));
	return 0;
}

