// Minimum cost to fill given weight in a bag  gfg||leetcode
#include<bits/stdc++.h>
using namespace std ;
#define bigNum 1000000
vector< vector<int> > dp(1005,vector<int>(1005));

int val(int i , int w){
	if(i>=1 && w>= 0)
		return dp[i][w];
	else 
		return bigNum;
}

int main(){
	int t , n , w , ans ;
	cin>>t;

	while(t--){
		cin>>n>>w;
		vector<int> cost(n+1);
		for(int i=1;i<=n;i++)
			cin>>cost[i];

		for(int i=1;i<=n;i++){
			for(int j=0;j<=w;j++){
				if(j==0)				dp[i][j] = 0;
				else if(cost[i]==-1)	dp[i][j] = val(i-1,j);
				else 					dp[i][j] = min(cost[i] + val(i,j-i), val(i-1,j) );

				//cout<<dp[i][j]<<" ";
			}
			//cout<<endl;
		}

		if(dp[n][w] == bigNum)
			cout<<"-1"<<endl;
		else
			cout<<dp[n][w]<<endl;
	}
	return 0;
}