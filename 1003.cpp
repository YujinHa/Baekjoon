#include <iostream>
using namespace std;

int main()
{
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		int j;
		int one2 = 1, zero2 = 0, one1 = 0, zero1 = 1, one = 0 , zero = 0;
		int N;

		scanf("%d", &N);
		if (N == 0)
			printf("1 0\n");
		else if (N == 1)
			printf("0 1\n");
		else
		{
			j = 2, one2 = 1, zero2 = 0, one1 = 0, zero1 = 1, one = 0, zero = 0;
			while (j <= N)
			{
				one = one1 + one2;
				zero = zero1 + zero2;
				one1 = one2;
				zero1 = zero2;
				one2 = one;
				zero2 = zero;
				j++;
			}
			printf("%d %d\n", zero2, one2);
		}
	}
	return 0;
}