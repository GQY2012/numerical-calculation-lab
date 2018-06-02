#include <iostream>
#include <cstdio>
#include <windows.h>
/*
	�ϻ���ҵ��3-ţ�ٲ�ֵ����ʽ����
*/

using namespace std;

#define N 6

typedef struct Point {
	double x;
	double y;
}Point;


int main() {

	Point P[N] = { 1920,105711,1930,123203,1940,131669,1950,150697,1960,179323,1970,203212 };

	while (true) {
		double year = 0.0;
		double population = 0.0;	//x(1920~1970)��ֵ
		double *diff = new double[N];
		double tmp = 1.0 ;
		cout << "�������,����-1�˳�" << endl;
		cin >> year;
		if (year == -1)
			return 0;

		for (int i = 0;i < N;i++) 
			diff[i] = P[i].y;
		for (int i = 0;i < N-1;i++) {
			for (int j = N-1;j > i;j--) {
				diff[j] = (diff[j] - diff[j - 1]) / (P[j].x - P[j - 1 - i].x);
			}
		}

		population = diff[0];
		for (int i = 0;i < N-1;i++) {
			tmp *= year - P[i].x;
			population += tmp * diff[i + 1];
		}

		printf("1920~1970��ֵ��%d\n", (int)population);
	}

	system("pause");
	return 0;
}