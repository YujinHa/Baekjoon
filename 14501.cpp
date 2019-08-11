#include <iostream>
#include <vector>
using namespace std;

int Max = -1;

void Sum(int *P, vector<int> index, int N)
{
	int sum = 0;
	for (int i = 0; i < index.size(); i++)
		sum += P[index[i]];

	if (sum > Max)
		Max = sum;
}

void Set(int i, int *T, int *P, vector<int> index, int N)
{
	for (int j = i; j < N; j++)
	{
		if (j + T[j] > N)
			Sum(P, index, N);
		else
		{
			index.push_back(j);
			if (j != N - 1)
				Set(j + T[j], T, P, index, N);

			Sum(P, index, N);
			index.erase(index.end() - 1);
		}
	}
}

int main()
{
	int N;
	cin >> N;
	int *T = new int[N];
	int *P = new int[N];
	vector<int> index;
	
	for (int i = 0; i < N; i++)
		cin >> T[i] >> P[i];
	
	Set(0, T, P, index, N);
	cout << Max << "\n";
	return 0;
}
