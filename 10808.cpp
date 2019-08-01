#include<iostream>
using namespace std;

int main()
{
	char* word = new char[100];
	int count[26] = { 0 };

	cin >> word;

	for (int i = 0; word[i] != '\0'; i++)
		count[(int)word[i]-97]++;

	for (int i = 0; i < 26; i++)
		cout << count[i] << " ";

	cout << endl;

	return 0;
}
