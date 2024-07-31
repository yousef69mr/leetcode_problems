// best_time_to_buy_and_sell.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
	int profit = 0, max_profit = 0;

	for (int i = 0; i < prices.size() - 1; i++) {
		vector<int> profitDays = { prices.begin() + i + 1,prices.end() };
		int max_number = *max_element(profitDays.begin(), profitDays.end());
		if (max_number == 0) {
			break;
		}
		max_profit = max_number - prices[i];
		if (max_profit > profit) {
			profit = max_profit;
		}
	}

	return profit;
}

int main()
{
	vector<int> prices_1 = { 7,1,5,3,6,4 };
	vector<int> prices_2 = { 7,6,4,3,1 };

	cout << maxProfit(prices_1) << endl;
	cout << maxProfit(prices_2) << endl;
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
