class Solution {
public:
    
    string shortestCommonSupersequence(string str1, string str2) {
        
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
             for(int i=0;i<=n;i++){
                 for(int j=0;j<=m;j++) cout<<dp[i][j]<< " ";
                 cout<<"\n";
             }
             cout<<dp[n][m];
             string lcs="";
             int len=dp[n][m];
             int x=n,y=m,k=len-1;
             while(x>0 && y>0){
                 if(str1[x-1]==str2[y-1]){
                     x--;
                     y--;
                     lcs.push_back(str1[x]);
                 }else if (dp[x-1][y]>dp[x][y-1]){ 
                     x--;
                     lcs.push_back(str1[x]);                            
                 }
                  else {
                      y--;
                      lcs.push_back(str2[y]);
                  }
             }
             while(x>0) {lcs.push_back(str1[x-1]);x--;};
             while(y>0) {lcs.push_back(str2[y-1]);y--;};
             reverse(lcs.begin(),lcs.end());
             return lcs;
           
             
        
    }
};
