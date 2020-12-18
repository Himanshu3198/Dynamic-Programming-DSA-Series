#include<bits/stdc++.h>
using namespace std;

int CoinChange(int arr[],int n,int sum){
    int c[sum][n];
    for(int i=0;i<n;i++)
    {
         c[0][i]=1;
    }
       

        for(int i=1;i<sum+1;i++){
            for(int j=0;j<n;j++){
                int x=(i-arr[j]>=0)?c[i-arr[j]][j]:0;
               int  y=(j>=1)?c[i][j-1]:0;
               c[i][j]=x+y;
            }
        }
        return c[sum][n-1];

}

int main(){

    int arr[]={1,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum=4;
    cout<<CoinChange(arr,n,sum)<<"\n";
}





