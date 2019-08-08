#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool comp(pair<vector<int>, string> a, pair<vector<int>, string> b)
{
	if (a.first[0] < b.first[0])
		return true;
	else if (a.first[0] == b.first[0])
	{
		if(a.first[1] < b.first[1])
			return true;
	}
	return false;
}

int main()
{
	int N, temp, num = 0;
	cin >> N;
	vector<pair<vector<int>, string>> S(N);
	for (int i = 0; i < N; i++)
	{
		cin >> temp >> S[i].second;
		S[i].first.push_back(temp);
		S[i].first.push_back(num++);
	}
	sort(S.begin(), S.end(), comp);

	for (int i = 0; i < N; i++)
		cout << S[i].first[0] << " " << S[i].second << "\n";

	return 0;
}
