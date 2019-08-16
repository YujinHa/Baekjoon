#include <iostream>
#include <algorithm>
using namespace std;

int check = 0;

void divide(int start, int end, int *A, int ave)
{
	int mid = (start + end) / 2;
	if (mid == start)
	{
		if (A[start] <= ave)
			check = mid + 1;
		else
			check = 0;
		return;
	}
	if (ave >= A[mid])
		divide(mid, end, A, ave);
	else
		divide(start, mid, A, ave);
}

int main()
{
	int N, M, ave;
	long sum = 0;
	scanf("%d", &N);
	int *A = new int[N];

	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	scanf("%d", &M);
	for (int i = 0; i < N; i++)
		sum += A[i];
	sort(A, A + N);
	if (sum <= M)
		printf("%d\n", A[N - 1]);
	else
	{
		ave = M / N;
		divide(0, N - 1, A, ave);
		sum = 0;
		for (int i = 0; i < check; i++)
			sum += A[i];

		for (int i = check; i < N; i++)
		{
			if (A[i] <= (M - sum) / (N - check))
			{
				sum += A[i];
				check++;
			}
		}
		printf("%ld\n", (M - sum) / (N - check));
	}
	return 0;
}