// climbing_stairs_problem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int static climbStairs(int n) {

	// a=dp[0]
	// b=dp[1]

	int a = 1, b = 1, c = a + b;

	if (n == 1 || n == 0) return 1;
	// a b c
	//   a b c
	// 1 1 2
	//   1 2 3
	// function f(n)=f(n-1)+(n-2)
	for (int step = 2; step <= n; step++) {
		c = a + b;
		a = b;
		b = c;
	}

	return c;
}

int main()
{
	std::cout << climbStairs(1);

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
