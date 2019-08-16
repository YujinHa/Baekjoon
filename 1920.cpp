#include <iostream>
#include <algorithm>
using namespace std;

int check = 0;

void divide(int start, int end, int *A, int m)
{
	int mid = (start + end) / 2;
	if (mid == start)
	{
		if(m == A[start])
			check = 1;
		return;
	}
	if((m == A[mid]) || (m == A[start]) || (m == A[end]))
		check = 1;
	else if (m > A[mid])
		divide(mid, end, A, m);
	else
		divide(start, mid, A, m);
}

int main()
{
	int N, M, m;
	scanf("%d", &N);
	int *A = new int[N];

	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	scanf("%d", &M);
	sort(A, A + N);

	for (int i = 0; i < M; i++)
	{
		check = 0;
		scanf("%d", &m);
		divide(0, N - 1, A, m);
		if (check == 1)
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}