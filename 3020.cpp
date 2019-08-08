#include <iostream>
using namespace std;

int main()
{
	int N, H, S1, S2, diff=0, check=1;
	scanf("%d %d", &N, &H);
	int up[500001] = {0,};
	int down[500001] = {0,};
	int min = 200001;

	for (int i = 0; i < N / 2; i++)
	{
        scanf("%d", &S1);
        scanf("%d", &S2);
        up[S1]++;
        down[S2]++;
	}
    for (int i = H - 1; i > 0; i--)
        up[i] += up[i + 1];
    for (int i = H - 1; i > 0; i--)
        down[i] += down[i + 1];
    
	for (int i = 1; i <= H; i++)
	{
		diff = up[i] + down[H - i + 1];
		if (diff < min)
		{
			min = diff;
			check = 1;
		}
		else if (diff == min)
			check++;
	}
	printf("%d %d\n", min, check);
	return 0;
}
