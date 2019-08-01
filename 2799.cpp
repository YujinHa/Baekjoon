#include<iostream>
#include<string>
using namespace std;

int main()
{
	int M, N;
	cin >> M >> N;

	string* code = new string[5 * M + 1];
	int result[5] = {0};

	for (int i = 0; i < 5 * M + 1; i++)
	{
		cin >> code[i];
	}
	for(int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int check = 0;
			for (int k = 1; k < 5; k++)
			{
				if (code[5 * j + k][5 * i + 1] == '*')
					check++;
			}
			result[check]++;
		}
	}
	for (int i = 0; i < 5; i++)
		cout << result[i] << " ";

	return 0;
}
