class Solution {
public:
int giveLcs(string str1, string str2) {
        
             int n=str1.size(),m=str2.size();
             int dp[n+1][m+1];
             for(int i=0;i<=n;i++){
                 for(int j=0;j<=m;j++){
                     if(i==0 || j==0){
                         dp[i][j]=0;
                         continue;
                     }
                     if(str1[i-1]==str2[j-1]){
                         dp[i][j]=1+dp[i-1][j-1];
                     }else{
                         dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                     }
                 }
             }
            return dp[n][m];
}

    int minInsertions(string s) {
     
          string t=s;
          reverse(t.begin(),t.end());
         int common=giveLcs(s,t);
         cout<<common<<"\n";
         return s.size()-common;
    }
};
