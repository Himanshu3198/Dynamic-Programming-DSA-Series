#include<bits/stdc++.h>
using namespace std;

 void longestPalinseq (string s)
{
    // your code here
       string t=s;
          int n=s.length();
          reverse(s.begin(),s.end());
        
        
          int dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        
         
        for(int i=1;i<=n;i++){
            
            for(int j=1;j<=n;j++){
                
                if(s[i-1]==t[j-1]){
                    
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
         cout<<dp[n][n]<<"\n";
    
  
        
}
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

         longestPalinseq (S);
    }
}



