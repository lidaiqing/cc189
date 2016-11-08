#include <bits/stdc++.h>

using namespace std;

void rotate(int N, int a[4][4])
{
	for (int i = 0; i < N / 2; i++)
	{
		int first = i;
		int last = N - 1 - first;
		for (int j = first; j < last; j++)
		{
			int offset = j - first;
			int top = a[first][j];
			a[first][j] = a[last-offset][first];
			a[last-offset][first] = a[last][last-offset];
			a[last][last-offset] = a[j][last];
			a[j][last] = top;
		}
	}
}

int main()
{
	int test[][4] = { {1,2,3,4}, {5,6,7,8}, {9, 10, 11, 12}, {13, 14, 15, 16} };
	int N = 4;
	cout << "Testing array: " << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << test[i][j] << " ";
		cout << endl;
	}
	cout << "Result:" << endl;
	rotate(N, test);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << test[i][j] << " ";
		cout << endl;
	}
}
