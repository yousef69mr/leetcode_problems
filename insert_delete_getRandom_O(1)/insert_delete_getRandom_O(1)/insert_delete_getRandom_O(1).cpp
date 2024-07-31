// insert_delete_getRandom_O(1).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include "RandomizedSet.h"
#include<unordered_map>
#include<random>


using namespace std;




class RandomizedSet
{

private:

	vector<int> nums;
	unordered_map<int, int> index;
	default_random_engine generator;

public:
	//unordered_map<int, int> memo;

	RandomizedSet() {
		this->nums = {};
		this->index = {};
	}

	bool insert(int val) {


		auto iterator = find(nums.begin(), nums.end(), val);
		if (!this->nums.empty() && iterator != this->nums.end()) {
			return false;
		}


		this->nums.emplace_back(val);
		this->index[val] = this->nums.size() - 1;

		return true;
	}

	bool remove(int val) {

		auto iterator = find(nums.begin(), nums.end(), val);

		if (this->nums.empty() || iterator == this->nums.end()) {
			return false;
		}


		int last_num = nums.back();

		nums[index[val]] = last_num;
		index[last_num] = index[val];

		nums.pop_back();
		index.erase(val);

		return true;

	};


	int getRandom() {
		uniform_int_distribution<int> distribution(0, this->nums.size() - 1);

		return this->nums[distribution(generator)];
	}
};



int main()
{
	RandomizedSet set = RandomizedSet();

	cout << set.insert(5) << endl;
	cout << set.insert(5) << endl;
	cout << set.insert(3) << endl;
	cout << set.insert(4) << endl;
	cout << set.remove(5) << endl;
	cout << set.getRandom() << endl;
	cout << set.getRandom() << endl;
	cout << set.getRandom() << endl;


	return 0;
}

