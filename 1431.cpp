#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

int comp(const string& A, const string& B)
{
	int suma = 0, sumb = 0;
	if (A.size() != B.size())
	{
		if (A.size() < B.size())
			return 1;
		else
			return 0;
	}
	else
	{
		for (int i = 0; i < A.size(); i++)
		{
			if ((int(A[i]) >= 48) && (int(A[i]) <= 57))
				suma += int(A[i]) - 48;
		}
		for (int i = 0; i < B.size(); i++)
		{
			if ((int(B[i]) >= 48) && (int(B[i]) <= 57))
				sumb += int(B[i]) - 48;
		}
		if (suma < sumb)
			return 1;
		else if (suma > sumb)
			return 0;
		else
		{
			if (A < B)
				return 1;
			else
				return 0;
		}
	}
}

int main()
{
	int N;
	cin >> N;
	string *s = new string[N];

	for (int i = 0; i < N; i++)
		cin >> s[i];
	sort(s, s+N, comp);

	for (int i = 0; i < N; i++)
		cout << s[i] << "\n";

	return 0;
}