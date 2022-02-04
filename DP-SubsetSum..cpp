#include<bits/stdc++.h>
using namespace std;


// time  and space complexity :O(n*sum)
//  memoization 
          int dp[100][10001];
           int solve(int n,int arr[],int sum,int idx){
              
              
               if(sum==0){
                  
                  return dp[idx][sum]=1;
              }
              
              if(idx>=n){
                  return 0;
              }
              
             
               if(dp[idx][sum]!=-1){
                  return dp[idx][sum];
              }
              
              
              if(arr[idx]>sum){
                  return dp[idx][sum]=solve(n,arr,sum,idx+1);
              }
              
              return dp[idx][sum]= (solve(n,arr,sum,idx+1) || solve(n,arr,sum-arr[idx],idx+1));
          }
    bool isSubsetSum(int N, int arr[], int sum){
     
     
           // code here 
           memset(dp,-1,sizeof(dp));
           return solve(N,arr,sum,0);
    }


//  tabulation 
   bool SubsetSum(int set[],int n,int sum){
   	bool subset[n+1][sum+1];
   	for(int i=0;i<=n;i++)
   	{
   		subset[i][0]=true;
	   }
	   for(int i=1;i<=sum;i++)
	   {
	   	subset[0][i]=false;
	   }
	   for(int i=1;i<=n;i++)
	   {
	   	for(int j=1;j<=sum;j++)
	   	{
	   		if(j<set[i-1])
	   		subset[i][j]=subset[i-1][j];
	   		if(j>=set[i-1])
	   		{
	   			subset[i][j]=subset[i-1][j] ||subset[i-1][j-set[i-1]];
			   }
		   }
	   }
	   for(int i=0;i<=n;i++)
	   {
	   	for(int j=0;j<=sum;j++)
	   	{
	   		cout<<subset[i][j]<<" ";
		   }
		   cout<<endl;
	   }
	   return subset[n][sum];
	   
   }
  
  int main(){
  	int set[]={ 3, 34, 4, 12, 5, 2 }; 
  	int sum=9;
  	int n=sizeof(set)/sizeof(set[0]);
  	if(SubsetSum(set,n,sum))
  	cout<<"found subset\n";
  	else
  	cout<<"subset not found\n";
  	return 0;
  }
