#include <bits/stdc++.h>

using namespace std;

string stringCompression(string s)
{
	string compressString = "";
	int count = 0;
	for (int i = 0; i < s.size(); i++)
	{
		count++;
		if (i + 1 >= s.size() || s[i+1] != s[i])
		{
			compressString += s[i];
			char charCount = count + '0';
			compressString += charCount;
			count = 0;
		}
	}
	if (compressString.size() < s.size()) return compressString;
	return s;
}

int main()
{
	string input = "aabcccccaaa";
	cout << "Testing input " << input << endl;
	cout << "Result: " << stringCompression(input) << endl;
	return 0;
}
