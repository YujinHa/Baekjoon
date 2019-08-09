#include <iostream>
using namespace std;

int main()
{
	int N, M, safe=0, max = -1,check = 0;
	int a[2] = { 0, };
	int b[2] = { 0, };
	cin >> N >> M;
	int **temp = new int*[N];
	int **virus = new int*[N];//바뀌는 배열
	for (int i = 0; i < N; i++)
	{
		temp[i] = new int[M];
		virus[i] = new int[M];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> virus[i][j];
			temp[i][j] = virus[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (virus[i][j] == 0)
			{
				virus[i][j] = 1;
				a[0] = i;
				a[1] = j;
				for (int i2 = i; i2 < N; i2++)
				{
					int j2;
					if (i2 == i)
						j2 = j+1;
					else
						j2 = 0;
					for (j2; j2 < M; j2++)
					{
						if (virus[i2][j2] == 0)
						{
							virus[i2][j2] = 1;
							b[0] = i2;
							b[1] = j2;
							for (int i3 = i2; i3 < N; i3++)
							{
								int j3;
								if (i3 == i2)
									j3 = j2+1;
								else
									j3 = 0;
								for (int j3 = 0; j3 < M; j3++)
								{
									virus[a[0]][a[1]] = 1;
									virus[b[0]][b[1]] = 1;
									if (virus[i3][j3] == 0)
									{
										virus[i3][j3] = 1;
										
										while (1)
										{
											for (int k = 0; k < N; k++)//바이러스 퍼지게
											{
												for (int l = 0; l < M; l++)
												{
													if (virus[k][l] == 2)
													{
														if (k >= 1)
														{
															if (virus[k - 1][l] == 0)
															{
																virus[k - 1][l] = 2;
																check++;
															}
														}
														if (k < N -1)
														{
															if (virus[k + 1][l] == 0)
															{
																virus[k + 1][l] = 2;
																check++;
															}
														}
														if (l >= 1)
														{
															if (virus[k][l - 1] == 0)
															{
																virus[k][l - 1] = 2;
																check++;
															}
														}
														if (l < M - 1)
														{
															if (virus[k][l + 1] == 0)
															{
																virus[k][l + 1] = 2;
																check++;
															}
														}
													}
												}
											}
											if (check == 0)
												break;
											check = 0;
										}
										safe = 0;
										for (int k = 0; k < N; k++)//안전지역 구하기
										{
											for (int l = 0; l < M; l++)
											{
												if (virus[k][l] == 0)
													safe++;
											}
										}
										if (safe > max)
											max = safe;
									}
									for (int k = 0; k < N; k++)//배열 리셋
									{
										for (int l = 0; l < M; l++)
											virus[k][l] = temp[k][l];
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout << max << endl;

	return 0;
}