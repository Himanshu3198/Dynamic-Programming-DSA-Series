class Solution {
public:
//    lcs
    bool isSubsequence(string s, string t) {
        
        
        int n=s.size();
        int m=t.size();
        
         int dp[n+1][m+1];
        
         memset(dp,0,sizeof(dp));
        
        int maxlen=0;
        for(int i=1;i<=n;i++){
            
            for(int j=1;j<=m;j++){
                
                
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
               
            }
        }
        
        
         
        
        return dp[n][m]==n;
    }
};

//  two pointers
class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        
        int n=s.size();
        int m=t.size();
        
        
        
        int i=n-1,j=m-1;
        
        
        while(i>=0 and j>=0){
            
            if(s[i]==t[j]){
                i--;
                j--;
            }else{
                j--;
            }
        }
        
        return i==-1;

    }
};
