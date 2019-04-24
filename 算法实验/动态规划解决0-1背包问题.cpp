#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;  
 
const int N = 20; // N����Ʒ 
const int C = 40; // C�Ǳ����������� 
 
int main()  
{  
	int value[N + 1]  = {0,4,5,1,7,9,7,11,19,23,12,11,43,6,21,16,17,3,8,20,21}; // ��ֵ
	int weight[N + 1] = {0,5,7,2,3,2,3,7,13,17,6,4,27,2,11,9,8,1,4,8,9}; // ����
	int m[N + 1][C + 1] = {0}; // m[i][j]��ʾ�ڱ�������Ϊj������£� ǰi����Ʒ������ֵ

		
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= C; j++)
		{
			// ���ƹ�ϵʽ
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
			printf("%4d",m[i][j]);//�Զ����� 
		}
 
		cout << endl;
	}
	cout<<"   ����ܼ�ֵΪ��"<<m[20][40]<<endl;
	return 0;  
}  

