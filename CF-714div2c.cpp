#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7;
const int N=2e5+1000;
int dp[N];

void init(){
 for(int i=0;i<=9;i++)
    dp[i]=1;
 for(int i=10;i<N;i++)
      dp[i]=(dp[i-10]+dp[i-9])%mod;

}
int main(){
     ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     init();

     int t;
     cin>>t;
     
     while(t--){
         int num,m;
         cin>>num>>m;
         int ans=0;
         while(num){
             int x=num%10;
             ans=(ans+dp[x+m])%mod;
             num/=10;
         }
         cout<<ans<<"\n";
     }

}
