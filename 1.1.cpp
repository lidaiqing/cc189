#include <bits/stdc++.h>

using namespace std;

bool isUnique(string s)
{
	bool charTable[256];
	memset(charTable, 0, sizeof(charTable));
	for (int i = 0; i < s.size(); i++)
	{
		if (charTable[s[i]]) return false;
		charTable[s[i]] = true;
	}
	return true;
}


int main() {
	string input = "abcdefgg";
	cout << "Testing input abcdefgg" << endl;
	cout << "Result: " << isUnique(input) << endl;
}
