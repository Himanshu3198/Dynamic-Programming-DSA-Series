#include<bits/stdc++.h>
using namespace std;
    int longestPalinSubseq(string A) {
        //code here
        //  time complexity o(n*n)
        //  space complexity o(n)
        string B=A;
        reverse(B.begin(),B.end());
        
        
        int n=A.size();
        
        int dp[n+1][n+1];
        
        memset(dp,0,sizeof(dp));
        
        
        for(int i=1;i<=n;i++){
            
            for(int j=1;j<=n;j++){
                
                
                if(A[i-1]==B[j-1]){
                    
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return dp[n][n];
        
        
        
    }
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout<< longestPalinSubseq(S);
    }
}



