//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int a, b, c, qu, re;
//
//	for (int i = 1000; i < 10000; i++)
//	{
//		b = 0;
//		c = 0;
//		a = (i / 1000) + ((i / 100) % 10) + ((i / 10) % 10) + (i % 10);
//		qu = i;
//		while(1)
//		{
//			b += (qu % 12);
//			qu = (qu / 12);
//			if (qu == 0)
//				break;
//		}
//		qu = i;
//		while (1)
//		{
//			c += (qu % 16);
//			qu = (qu / 16);
//			if (qu == 0)
//				break;
//		}
//		if ((a == b) && (a == c) && (b == c))
//			cout << i <<"\n";
//	}
//	return 0;
//}