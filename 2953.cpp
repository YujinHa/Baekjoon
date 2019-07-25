#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int* score = new int[20];
	int num;
	int sum = -1;

	for (int i = 0; i < 5; i++)
	{
		cin >> score[i * 4] >> score[i * 4 + 1] >> score[i * 4 + 2] >> score[i * 4 + 3];

		if (score[i * 4] + score[i * 4 + 1] + score[i * 4 + 2] + score[i * 4 + 3] > sum)
		{
			num = i + 1;
			sum = score[i * 4] + score[i * 4 + 1] + score[i * 4 + 2] + score[i * 4 + 3];
		}
	}
	cout <<  num << " " << sum << endl;

	return 0;
}