// Minimum removals from array to make max – min <= K dp gfg 
#include<bits/stdc++.h>
using namespace std;
int main(){


    int n=9,k=4;
    // cin>>n;
    int a[n]={1, 3, 4, 9, 10, 11, 12, 17, 20} ;

    int dp[n];
    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    int j,ans=n-1;
    for(int i=1;i<n;i++){

         dp[i]=i;
         j=dp[i-1];

         while(i!=j and (a[i]-a[j])>k){


             j++;
         }

         dp[i]=min(dp[i],j);

         ans=min(ans,(n-(i-j+1)));
    }

    cout<<ans<<"\n";




}