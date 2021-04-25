
//  0/1 knapsack problem 
#include <bits/stdc++.h> 
using namespace std;
  


int knapSack(int W, int wt[], int val[], int n) 
{ 
     

        int dp[n+1][W+1];
        memset(dp,0,sizeof(dp));

        for(int i=1;i<=n;i++){

            for(int j=1;j<=W;j++){

                if(wt[i-1]>j){

                    dp[i][j]=dp[i-1][j];
                }
                else{
                    dp[i][j]= max(dp[i-1][j],dp[i-1][j-wt[i-1]]+val[i-1]);
                }
            }
        }

        return dp[n][W];
} 
  
int main() 
{ 
    int wt[] = {1,2,3 }; 
    int val[] = { 10,15,40}; 
    int W = 6; 
    int n = sizeof(val) / sizeof(val[0]); 
    printf("%d", knapSack(W, wt, val, n)); 
    return 0; 
} 





