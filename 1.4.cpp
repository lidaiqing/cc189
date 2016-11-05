#include <bits/stdc++.h>

using namespace std;

void upperTolower(string & s)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (isupper(s[i])) s[i] = tolower(s[i]);
	}
}

bool isPalindromePermutation(string s)
{
	// check if it is possible to found a palindrome
	// assume all chars are ascii and ignoring capital letters
	upperTolower(s);
	int charCount[256];
	memset(charCount, 0, sizeof(charCount));
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != ' ') charCount[s[i]]++;
	}
	int numOdd = 0;
	for (int i = 0; i < 256; i++)
	{
		if (charCount[i] % 2 == 1) numOdd++;
	}
	if (numOdd > 1) return false;
	return true;
}

int main()
{
	string input = "Tact Coa";
	cout << "Tesing input " << input << endl;
	cout << "Resule: " << isPalindromePermutation(input) << endl;
}
