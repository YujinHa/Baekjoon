#include<iostream>
#include<string>
using namespace std;

int main()
{
	int num;

	cin >> num;

	string word1;
	string word2;
	int diff;

	for (int i = 0; i < num; i++)
	{
		cin >> word1 >> word2;

		cout << "Distances:";
		for (int j = 0; j < word1.size(); j++)
		{
			if ((int)word1[j] - 64 <= (int)word2[j] - 64)
				diff = (int)word2[j] - (int)word1[j];
			else
				diff = (int)word2[j] - (int)word1[j] + 26;
			cout << " " << diff;
		}
		cout << endl;
	}

	return 0;
}
