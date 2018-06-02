#include <iostream>
#include <cstdio>
#include <windows.h>
/*
	上机作业题12-Doolittle直接分解法求解线性方程组
*/

using namespace std;

#define N 3		//方程阶数


int main()
{
	double a[N][N] = {	-1,3,2,
						0,1,1,
						3,2,0  };	//系数矩阵
	double b[N] = { 4,2,5 };	//常数项
	double l[N][N] = { 0 };	//L
	for (int k = 0;k < N;k++) {
		l[k][k] = 1;
	}
	double u[N][N] = { 0 };	//U
	double x[N] = { 0 };	//X
	double y[N] = { 0 };	//Y

	for (int k = 0;k < N;k++) {
		for (int j = k;j < N;j++) {	//计算U的第k行元素
			double tmp = 0;
			for (int r = 0;r <= k - 1;r++) {
				tmp += l[k][r] * u[r][j];
			}
			u[k][j] = a[k][j] - tmp;
		}

		for (int i = k + 1;i < N;i++) {	//计算L的第k列元素
			double tmp = 0;
			for (int r = 0;r <= k - 1;r++) {
				tmp += l[i][r] * u[r][k];
			}
			l[i][k] = (a[i][k] - tmp) / u[k][k];
		}
	}

	for (int i = 0;i < N;i++) {	//解方程组LY = b
		double tmp = 0;
		for (int j = 0;j <= i-1;j++) {
			tmp += l[i][j] * y[j];
		}
		y[i] = b[i] - tmp;
	}

	for (int i = N - 1;i >= 0;i--) {	//解方程组UX = Y
		double tmp = 0;
		for (int j = i + 1;j < N;j++) {
			tmp += u[i][j] * x[j];
		}
		x[i] = (y[i] - tmp) / u[i][i];
	}

	for (int i = 0;i < N;i++) {
		printf("X%d: %f\n", i + 1, x[i]);
	}

	system("pause");
	return 0;
}