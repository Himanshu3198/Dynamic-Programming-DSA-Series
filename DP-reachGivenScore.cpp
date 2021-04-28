// Reach a given score  gfg|| cpp

#include<bits/stdc++.h>
#define ll long long int
using namespace std;


long long int count(long long int n)
{
	long long int dp[4][n+1],i;
	memset(dp, 0, sizeof(dp));
	                // If 0 sum is required number of ways is 1.
	
	// Your code here
	const int mod=1e9+7;
	
	vector<int>score ={0,3,5,10};

	memset(dp,0,sizeof(dp));
	for(int i=1;i<=3;i++){
	    
	    for(int j=0;j<=n;j++){
	       if(j==0){
	           dp[i][j]=1;
	       }
	       else{
	           int inc=(score[i]>j)?0:dp[i][j-score[i]];
	           int exc=dp[i-1][j];
	           dp[i][j]=(inc+exc)%1000000007;
	       }
	    }
	}
	
	return dp[3][n]%1000000007;
	
	
}




int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
} 