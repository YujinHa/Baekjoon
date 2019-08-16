#include <iostream>
using namespace std;

int main()
{
	int T, Max;
	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		int n;
		int **S = new int*[2];
		
		scanf("%d", &n);
		for (int j = 0; j < 2; j++)
			S[j] = new int[n];
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < n; k++)
				scanf("%d", &S[j][k]);

		for (int j = n - 2; j >= 0; j--)
		{
			if (j == n - 2)
			{
				S[0][j] += S[1][j + 1];
				S[1][j] += S[0][j + 1];
			}
			else
			{
				S[0][j] += ((S[1][j + 1] >= S[1][j + 2]) ? S[1][j + 1] : S[1][j + 2]);
				S[1][j] += ((S[0][j + 1] >= S[0][j + 2]) ? S[0][j + 1] : S[0][j + 2]);
			}
		}
		printf("%d\n",S[0][0]>=S[1][0]?S[0][0]:S[1][0]);
	}
	return 0;
}