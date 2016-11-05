#include <bits/stdc++.h>

using namespace std;

void toggle(int& bitmask, int pos)
{
	int mask = (1 << pos);
	if (bitmask & mask)
	{
		bitmask &= ~mask;
	} else {
		bitmask |= mask;
	}
}

void upperTolower(string& s)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (isupper(s[i])) s[i] = tolower(s[i]);
	}
}

bool checkBitmask(int bitmask)
{
	return (bitmask & (bitmask - 1)) == 0;
}
bool isPalindromePermutation(string s)
{
	upperTolower(s);
	int bitmask = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			toggle(bitmask, s[i] - 'a');
	}
	return checkBitmask(bitmask);
}

int main()
{
	string input = "Tact Coa";
	cout << "Testing input " << input << endl;
	cout << "Result: " << isPalindromePermutation(input) << endl;
	return 0;
}

	
