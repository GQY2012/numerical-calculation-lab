#include <iostream>
#include <cstdio>
#include <windows.h>

using namespace std;

#define N 6

typedef struct Point {
	double x;
	double y;
}Point;


int main() {
	Point P1[N] = { 1920,105711,1930,123203,1940,131669,1950,150697,1960,179323,1970,203212 };
	Point P2[N] = { 1910,91772, 1920,105711,1930,123203,1940,131669,1950,150697,1960,179323 };

	while (true) {
		double year = 0.0;
		double population1 = 0.0;	//x(1920~1970)插值
		double population2 = 0.0;	//x(1910~1960)插值
		double population = 0.0;	
		double R = 0.0;				//误差估计
		double L1[N] = { 1,1,1,1,1,1 };
		double L2[N] = { 1,1,1,1,1,1 };
		cout << "输入年份,输入-1退出" << endl;
		cin >> year;
		if (year == -1)
			return 0;

		for (int i = 0;i < N;i++) {
			for (int j = 0;j < N;j++) {
				if (i == j)
					continue;
				L1[i] *= (year - P1[j].x) / (P1[i].x - P1[j].x);
				L2[i] *= (year - P2[j].x) / (P2[i].x - P2[j].x);
			}
		}
		for (int i = 0;i < N;i++) {
			population1 += L1[i] * P1[i].y;
			population2 += L2[i] * P2[i].y;
 		}

		R = (year - P2[0].x) / (P2[0].x - P1[N - 1].x) * (population1 - population2);

		printf("1920~1970插值：%d\n1910~1960插值：%d\n误差估计:%f\n", (int) population1,(int) population2, R);
	}

	system("pause");
	return 0;
}