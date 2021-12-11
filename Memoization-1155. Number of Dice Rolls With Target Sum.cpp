class Solution {
public:
       
       const int mod=1e9+7;
       
        int dp[32][1002];
     
    
       int solve(int d,int f,int target ){
           
         
           if(d==0 and target==0){
               return 1;
           }
           if(target==0 and d!=0){
              
               return 0;
           }
           
           if(d==0 and target!=0){
               return 0;
           }
             if(dp[d][target]!=-1){
               return dp[d][target];
           }
           
           

           int res=0;
           
           for(int i=1;i<=f;i++){
             if(i<=target){
                 
            res+=solve(d-1,f,target-i);
               res=res%mod;
             }
            
              
               
           }
           return dp[d][target]=res;
           
       }
    int numRollsToTarget(int d, int f, int target) {
     
       
          memset(dp,-1,sizeof(dp));
          return   solve(d,f,target);

        
          
        
       
    }
};
