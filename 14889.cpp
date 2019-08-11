#include <iostream>
using namespace std;

int Min = 2001, sum1 = 0, sum2 = 0, diff = 0;

void SetLink(int *start, int *link, int N)
{
	int check = 0, index = 0;

	for (int j = 0; j < N; j++)
	{
		if (start[check] == j)
		{
			if (check != N / 2 - 1)
				check++;
		}
		else
		{
			link[index] = j;
			index++;
		}
	}
}

void Sum(int *start, int *link, int **S, int N)
{
	int sum1 = 0, sum2 = 0, diff;
	for (int i = 0; i < N / 2; i++)
	{
		for (int j = 0; j < N / 2; j++)
		{
			sum1 += S[start[i]][start[j]];
			sum2 += S[link[i]][link[j]];
		}
	}
	diff = ((sum1 >= sum2) ? sum1 - sum2 : sum2 - sum1);

	if (diff < Min)
		Min = diff;
}

void SetStart(int i, int k, int *start, int *link, int **S, int N)
{
	for (int j = i; j < N; j++)
	{
		start[k] = j;
		if (k == (N / 2 - 1))
		{
			SetLink(start, link, N);
			Sum(start, link, S, N);
		}
		else
			SetStart(j + 1, k + 1, start, link, S, N);
	}
}

int main()
{
	int N;
	cin >> N;
	int **S = new int*[N];
	int *start = new int[N / 2];
	int *link = new int[N / 2];
	for (int i = 0; i < N; i++)
		S[i] = new int[N];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> S[i][j];
	}
	SetStart(0, 0, start, link, S, N);
	cout << Min << "\n";
	return 0;
}
