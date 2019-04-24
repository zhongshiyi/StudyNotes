#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;  
 
const int N = 20; // N件物品 
const int C = 40; // C是背包的总容量 
 
int main()  
{  
	int value[N + 1]  = {0,4,5,1,7,9,7,11,19,23,12,11,43,6,21,16,17,3,8,20,21}; // 价值
	int weight[N + 1] = {0,5,7,2,3,2,3,7,13,17,6,4,27,2,11,9,8,1,4,8,9}; // 重量
	int m[N + 1][C + 1] = {0}; // m[i][j]表示在背包容量为j的情况下， 前i件物品的最大价值

		
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= C; j++)
		{
			// 递推关系式
			if(j < weight[i])
			{
				m[i][j] = m[i - 1][j];
			}
			else
			{
				int x = m[i - 1][j];
				int y = m[i - 1][j - weight[i]] + value[i];
				m[i][j] = x < y ? y : x;
			}
		}
	}
 
	for(int i = N; i >= 1; i--)
	{
		for(int j = 1; j <= C; j++)
		{
			printf("%4d",m[i][j]);//自动对齐 
		}
 
		cout << endl;
	}
	cout<<"   最大总价值为："<<m[20][40]<<endl;
	return 0;  
}  

