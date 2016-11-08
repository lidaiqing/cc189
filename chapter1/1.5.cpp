#include <bits/stdc++.h>

using namespace std;

bool checkReplace(string s1, string s2)
{
	bool foundDiff = false;
	for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] != s2[i])
		{
			if (foundDiff) return false;
			foundDiff = true;
		}
	}
	return true;
}
bool checkInsert(string s1, string s2)
{
	int p1 = 0, p2 = 0;
	while (p1 < s1.size() && p2 < s2.size())
	{
		if (s1[p1] != s2[p2])
		{
			if (p1 != p2) // found diff already
				return false;
			p1++;
		} else {
			p1++;
			p2++;
		}
	}
	return true;
}

bool oneEditAway(string s1, string s2)
{
	if (s1 == s2) return true;
	if (s1.size() == s2.size()) return checkReplace(s1,s2);
	else if (s1.size() == s2.size() + 1) return checkInsert(s1,s2);
	else if (s1.size() == s2.size() - 1) return checkInsert(s2,s1);
	return false;
}

int main()
{
	string input1 = "pales";
	string input2 = "pale";
	cout << "Testing input " << input1 << " " << input2 << endl;
	cout << "Result: " << oneEditAway(input1, input2) << endl;
	return 0;
}	
