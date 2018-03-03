#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<algorithm>
#define MAX 100
using namespace std;

int a[MAX][MAX];
int b[MAX][MAX];
int n;
int dq(int i, int j)
{
	if (b[i][j] != -1)
		return b[i][j];
	if (i == n - 1)
		b[i][j] = a[i][j]; //µÝ¹é±ß½ç
	else
	{
		int x = dq(i + 1, j);
		int y = dq(i + 1, j + 1);
		b[i][j] = max(x, y) + a[i][j];
	}
	return b[i][j];  

}
int main(int argc, char **argv)
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j >= 0; --j)
		{
			cin >> a[i][j];
			b[i][j] = -1;
		}
	}
	int max = dq(0, 0);
	cout << max << endl;
	system("pause");
	return 0;
}