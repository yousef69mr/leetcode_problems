// insert_interval.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

bool static compareRows(const vector<int>& a, const vector<int>& b) {
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

vector<vector<int>> static insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
	if (newInterval.empty()) return intervals;

	intervals.emplace_back(newInterval);
	return merge(intervals);
}

int main()
{
	vector<vector<int>> intervals = { { 1,3 }, { 6,9 } };
	vector<int> newIntervals = { 2, 5 };
	printMatrix(insert(intervals, newIntervals));


	vector<vector<int>> intervals_2 = { { 1,2 }, { 3,5 },{ 6,7 },{ 8,10 },{ 12,16 } };
	vector<int> newIntervals_2 = { 4, 8 };
	printMatrix(insert(intervals_2, newIntervals_2));


	return 0;
}


