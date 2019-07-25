#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int compare(const void *a, const void *b)
{
	int a1 = *(int*)a;
	int b1 = *(int*)b;

	if (a1 < b1)
		return -1;
	else if (a1 == b1)
		return 0;
	else
		return 1;
}

int main()
{
	int numA, numB, start = 0;

	vector<int> Diff;
	cin >> numA >> numB;
	int *A = new int[numA];
	int *B = new int[numB];

	for (int i = 0; i < numA; i++)
		cin >> A[i];
	for (int i = 0; i < numB; i++)
		cin >> B[i];

	qsort(&A[0], numA, sizeof(int), compare);
	qsort(&B[0], numB, sizeof(int), compare);

	for (int i = 0; i < numA; i++)
	{
		if (start >= numB)
			Diff.push_back(A[i]);
		else if (A[i] < B[start])
			Diff.push_back(A[i]);
		else if (A[i] > B[start])
		{
			while ((A[i] > B[start]) && (start < numB))
				start++;
			if ((A[i] < B[start]) || (start >= numB))
				Diff.push_back(A[i]);
		}
		else
			start++;
	}

	if (Diff.size() == 0)
		cout << "0" << endl;
	else
	{
		cout << Diff.size() << endl;
		for (int i = 0; i < Diff.size(); i++)
			cout << Diff[i] << " ";
	}
	return 0;
}