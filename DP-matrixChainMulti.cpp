#include<bits/stdc++.h>
using namespace std;

int MatrixChainMultiplication(int a[],int n){
	int c[n+1][n+1],i,j,k;
	for(i=0;i<=n;i++){
		c[i][i]=0;

	}

	for(int len=2;len<=n;len++){
		for(i=1;i<=n-len+1;i++){
			j=i+len-1;
			c[i][j]=INT_MAX;
			for(k=i;j<n && k<=j-1;k++){
				int cost=c[i][k]+c[k+1][j]+a[i-1]*a[k]*a[j];
				if(cost<c[i][j])
				c[i][j]=cost;
			}
		}
	}

	// for(i=0;i<=n;i++)
	// {
	// 	for(j=0;j<=n;j++){
	// 		cout<<c[i][j]<<" " ;   code for print the table
	// 	}
	// 	cout<<"\n";
	// }
	return c[1][n-1];


}
int main(){
	int a[]={1,2,3,4};
	int n=sizeof(a)/sizeof(a[0]);
	cout<<"MatrixChainMultiplication is\t"<< MatrixChainMultiplication(a,n);
}


