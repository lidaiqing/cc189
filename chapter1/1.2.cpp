#include <bits/stdc++.h>

using namespace std;

bool isPermutation(string s1, string s2)
{
	if (s1.size() != s2.size()) return false;
	//assume ignoring space and capital letter
	int charCount[256];
	memset(charCount, 0, sizeof(charCount));
	for (int i = 0; i < s1.size(); i++)
	{
		charCount[s1[i]]++;
	}
	for (int i = 0; i < s2.size(); i++)
	{
		charCount[s2[i]]--;
		if (charCount[s2[i]] < 0) return false;
	}
	return true;
}

int main() {
	// Testing string
	string input1 = "abcdeeefff";
	string input2 = "fffabcdeee";
	cout << "Testing if " << input1 << " is permutation of " << input2 << endl;
	cout << "Result: " << isPermutation(input1, input2) << endl;
}
