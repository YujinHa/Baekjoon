#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	vector<pair<int, int>> p(N);
	int tempP1, tempP2;

	for (int i = 0; i < N; i++)
		scanf("%d %d", &p[i].first, &p[i].second);
	
	sort(p.begin(), p.end());

	for (int i = 0; i < N; i++)
		printf("%d %d\n", p[i].first,p[i].second);

	return 0;
}
