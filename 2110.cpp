#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int result = 1000000001;

void divide(int start, int end, int *X, vector<int> Cx, int N, int C)
{
	int mid = (start + end) / 2;
	int temp = X[0];
	if ((X[0] + X[N - 1]) / mid >= C - 1)
	{
		if (mid == start)
		{
			result = mid;
			cout << result << "\n";
			return;
		}
		Cx.push_back(X[0]);

		for (int i = 1; i < N; i++)
		{
			if (X[i] - temp >= mid)
			{
				Cx.push_back(X[i]);
				temp = X[i];
				if (Cx.size() == C)
				{
					Cx.clear();
					divide(mid, end, X, Cx, N, C);//mid °¡ i?
					break;
				}
			}
		}
	}
	if ((Cx.size() < C) && (result == 1000000001))
	{
		Cx.clear();
		divide(start, mid, X, Cx, N, C);
	}
}

int main()
{
	int N, C;
	cin >> N >> C;
	int *X = new int[N];
	vector<int> Cx;

	for (int i = 0; i < N; i++)
		cin >> X[i];

	sort(X, X + N);
	divide(1, X[N - 1], X, Cx, N, C);

	return 0;
}