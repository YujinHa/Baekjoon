//#include<iostream>
//using namespace std;
//
//void mergesort(int *S, int start, int end)
//{
//	if (start >= end)
//		return;
//
//	int mid = (start + end) / 2;
//	int i = start;
//	int j = mid + 1;
//	int *temp = new int[50];
//	int k = start;
//
//	mergesort(S, start, mid);
//	mergesort(S, mid + 1, end);
//
//	while ((i <= mid) && (j <= end))
//	{
//		if (S[i] >= S[j])
//			temp[k++] = S[j++];
//		else
//			temp[k++] = S[i++];
//	}
//	while (i <= mid)
//		temp[k++] = S[i++];
//	while (j <= end)
//		temp[k++] = S[j++];
//	for (int l = start; l < k; l++)
//		S[l] = temp[l];
//}
//
//int main()
//{
//	int N;
//	cin >> N;
//	int *A = new int[N];
//	int *B = new int[N];
//	int minS = 0;
//
//	for (int i = 0; i < N; i++)
//		cin >> A[i];
//	for (int i = 0; i < N; i++)
//		cin >> B[i];
//
//	mergesort(A, 0, N - 1);
//	mergesort(B, 0, N - 1);
//
//	for (int i = 0; i < N; i++)
//		minS += A[i]*B[N-1-i];
//
//	cout << minS;
//	return 0;
//}