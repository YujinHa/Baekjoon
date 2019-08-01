#include<iostream>
using namespace std;

int main()
{
	int e, f, c, bottle, result = 0;

	cin >> e >> f >> c;

	bottle = e + f;

	while ((bottle / c) != 0)
	{
		result += bottle / c;
		bottle = (bottle / c) + (bottle % c);
	}
	cout << result << endl;

	return 0;
}
