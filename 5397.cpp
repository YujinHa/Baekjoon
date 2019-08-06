#include <iostream>
#include <string>
#include <list>
using namespace std;

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string code;
		cin >> code;
		list<char> result;
		list<char>::iterator cursor = result.begin();

		for (int j = 0; j < code.size(); j++)
		{
			if (code[j] == '<')
			{
				if (cursor != result.begin())
					cursor--;
			}
			else if (code[j] == '>')
			{
				if (cursor != result.end())
					cursor++;
			}
			else if (code[j] == '-')
			{
				if (cursor != result.begin())
				{
					cursor--;
					result.erase(cursor++);
				}
			}
			else
				result.insert(cursor, code[j]);
		}
		for(cursor = result.begin(); cursor != result.end(); cursor++)
			cout << *cursor;
		cout << endl;
	}

	return 0;
}