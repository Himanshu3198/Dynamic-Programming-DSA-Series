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
             cout<<dp[n][m];
             string lcs="";
             int len=dp[n][m];
             for(int i=0;i<len;i++) lcs+='h';
             int x=n,y=m,k=len-1;
             while(x>0 && y>0){
                 
                 if(str1[x-1]==str2[y-1]){
                     x--;
                     y--;
                     lcs[k--]=str1[x];
                 }else if (dp[x-1][y]>dp[x][y-1]) x--;
                  else y--;
             }
             return lcs;
           
