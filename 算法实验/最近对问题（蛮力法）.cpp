#include<iostream>
#include<math.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>

using namespace std;

const int N = 100;

//最近对算法
double ClosestPoints(double P[][2],int n,int &ind1, int &ind2) {
	double mind = 10 ^ 5;
	double dis = 0;
	for (int i = 0; i <= n - 1; i++)
		for (int j = i + 1; j <= n - 1; j++) {
			dis = (P[j][0] - P[i][0])*(P[j][0] - P[i][0]) + (P[j][1] - P[i][1]) *(P[j][1] - P[i][1]);
			if (dis < mind) {
				mind = dis;
				ind1 = i;
				ind2 = j;
			}
		}
	return mind;		
}

int main()
{
	
	double P[N][2],M;
	int n;//规模
	int a, b;
	//设置控制台名称
	SetConsoleTitle("用蛮力法解决最近对问题");
	srand(time(0));//随机种子
	/*cout << "输入点的个数：";
	cin >> n;*/
	n = 20;
	cout << "随机生成20个点，如下：" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			//cinP[i][j];
			P[i][j] = (rand() % 50);
		}
		cout << "(";
		for (int j = 0; j < 2; j++)
		{
			if (j == 1)
				cout << ",";
			cout << P[i][j];
		}
		cout << ")" << endl;
	}
	cout << endl;
	M = ClosestPoints(P, n, a, b);
	cout << "最近两点：P1(" << P[a][0] << "," << P[a][1] << ")和P2(" 
		<< P[b][0] << "," << P[b][1] << ")" << endl;
	cout << "最短距离：" << sqrt(M) << endl;
	
	return 0;
}