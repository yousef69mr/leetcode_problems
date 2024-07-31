// reverse_words_string.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include <sstream>

using namespace std;


vector<string> static split(const string& s) {
	istringstream iss(s);
	vector<string> tokens;
	string token;
	while (iss >> token) {
		tokens.push_back(token);
	}
	return tokens;
}


string static reverseWords(string s) {

	string result = "";
	vector<string> words = split(s);


	int i;
	for (i = words.size() - 1; i >= 0; i--) {
		result += words[i];

		if (i == 0) break;

		result += ' ';
	}
	return result;
}

int main()
{
	cout << reverseWords("the sky is blue") << endl;
	cout << reverseWords("  hello world  ") << endl;
	cout << reverseWords("a good   example") << endl;

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
