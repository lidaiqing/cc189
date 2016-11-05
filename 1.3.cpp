#include <bits/stdc++.h>

using namespace std;

void URLify(string& s, int n)
{
	int p1 = n - 1; //pointer to the actual end
	int p2 = s.size() - 1; //pointer to free space end
	
	for (; p1 >= 0; p1--)
	{
		if (s[p1] == ' ')
		{
			s[p2] = '0';
			s[p2-1] = '2';
			s[p2-2] = '%';
			p2 = p2 - 3;
		} else {
		s[p2--] = s[p1];
		}
	}
}

int main() 
{
	string input = "Mr John Smith    ";
	int n = 13;
	cout << "Testing URLify " << input << endl;
	URLify(input, n);
	cout << "Result: " << input << endl;
}
