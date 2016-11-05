#include <bits/stdc++.h>

using namespace std;

void zeroMatrix(int a[4][5], int M, int N)
{
	bool col[N], row[M];
	memset(col, 0, sizeof(col));
	memset(row, 0, sizeof(row));
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			if (a[i][j] == 0) {
				col[j] = 1;
				row[i] = 1;
			}
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			if (col[j] || row[i]) a[i][j] = 0;
}

int main()
{
	int test[][5] = { {1,1,0,0,1}, {0,0,1,1,1}, {1,1,1,1,1}, {1,0,1,1,1} };
	cout << "Testing input: " << endl;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << test[i][j] << "  ";
		}
		cout << endl;
	}
	zeroMatrix(test, 4, 5);
	cout << "Result:" << endl;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << test[i][j] << "  ";
		}
		cout << endl;
	}
}
