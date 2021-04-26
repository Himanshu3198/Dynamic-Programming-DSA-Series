#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

int main()
 {
	int t ;
	cin >> t ;
	while(t--){
	    int n , i , step[3] , j ;
	    cin >> n ;
	    cin >> step[0] >> step[1] >> step[2] ;
	    sort(step , step+3) ;
	    int dp[n+1] ;
	    for(i=0;i<n+1;i++){
	        dp[i] = INT_MIN ;
	    }
	    dp[0] = 0 ;
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=0;j<3;j++)
	            if(step[j]<=i)
	                dp[i]=max(dp[i],dp[i-step[j]]+1);
	    }
	    cout << dp[n] << endl ;
	}
	
	return 0;
}