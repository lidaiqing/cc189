#include <bits/stdc++.h>

using namespace std;

bool isStringRotate(string s1, string s2)
{
	// double s1 and check if s2 is a substring of s3
	string s3 = s1 + s1;
	return (s3.find(s2) != string::npos);
}

int main()
{
	string input1 = "waterbottle";
	string input2 = "erbottlewat";

	cout << "Testing " << input1 << " " << input2 << endl;
	cout << "Result: " << isStringRotate(input1, input2) << endl;
}
