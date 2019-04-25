#include<iostream>

using namespace std;
//最大子段和 
int MaxSum(int a[][20],int n){
	int sum = 0,b = 0;
	for(int i = 1;i < n;i++){
		if(b > 0){
			b += a[0][i];
			a[1][i] = b; 
		}	
		else{
			b = a[0][i];
			a[1][i] = b;
		}	
		if(b > sum){
			sum = b;
		}
		a[2][i] = sum;
	}
	return sum;
}

int main(){
	int A[3][20] = {2,11,-4,13,-5,-2,11,-13,25,-32,-12,15,16,13,-24,15,35,-4,-12,15};
	int n = 20;
	int sum = MaxSum(A,n);
	cout<<"a   = ";
	for(int i = 0;i < 3;i++){
		for(int j = 0;j < n;j++)
			printf("%4d",A[i][j]);
		cout<<endl;
		if(i == 0)
			cout<<"b   = ";
		else if(i == 1)
			cout<<"sum = ";
	}	
	cout<<"----------------------------"<<endl;
	cout<<"SUM = "<<sum<<endl;	
//	cout<<MaxSum(n,A)<<endl;
}

