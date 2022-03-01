class Solution {
public:
/*  time complexity O(nlogn) 
    
    0 --> 0
    1 --> 1
    2 --> 10
    3 --> 11
    4 --> 100
    5 --> 101
    
    when n is even  the number of set bit is equal to n/2 
    and when n is odd the number of set bit is equal to 1+n/2
    
    */
    
    long long solve(int n,int *dp){
        
        
        if(n==0){
            return dp[n]=0;
        }
        if(n==1){
            return dp[n]=1;
        }
        
        if(dp[n]!=-1){
            return dp[n];
        }
        
        if(n%2==0){
            
            return dp[n]=solve(n/2,dp);
        }else{
            return dp[n]=1+solve(n/2,dp);
        }
        
    }

    vector<int> countBits(int n) {
        
        vector<int>res(n+1);
         int dp[100001];
        memset(dp,-1,sizeof(dp));
        
        
         
         for(int i=0;i<=n;i++){
             
             res[i]=solve(i,dp);
         }
        
        return res;
        
        
    
    }
};
