#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

int comp(const string& A, const string& B)
{
	if (A.size() != B.size())
	{
		if (A.size() < B.size())
			return 1;
		else
			return 0;
	}
	else
	{
		if (A < B)
			return 1;
		else
			return 0;
	}
}

int main()
{
	int N;
	cin >> N;
	string *s = new string[N];
	string temp;

	for (int i = 0; i < N; i++)
		cin >> s[i];
	sort(s, s + N, comp);
	temp = s[0];
	for (int i = 0; i < N; i++)
	{
		if (i == 0)
			cout << s[i] << endl;
		else
		{
			if (s[i] != temp)
			{
				cout << s[i] << "\n";
				temp = s[i];
			}
		}
	}
	return 0;
}