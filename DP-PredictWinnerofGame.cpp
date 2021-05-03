// 486. Predict the Winner

class Solution {
public:
    
      long long dp[21][21][2];
    
    
        int win (vector<int>&nums,int i ,int j,int chance){
            
            
               if(i>j){
                   return 0;
               }
            
               if(dp[i][j][chance]!=-1)
                   return dp[i][j][chance];
               
               
                if( chance==0)
                   return dp[i][j][chance]=max(nums[i]+win(nums,i+1,j,1),nums[j]+win(nums,i,j-1,1));
                
                 else
                   return  dp[i][j][chance]=min(win(nums,i+1,j,0),win(nums,i,j-1,0));
                 
        }
    
    
    bool PredictTheWinner(vector<int>& nums) {
        
        int n=nums.size();
          memset(dp,-1,sizeof(dp));
        
        long long player1=0,player2=0;
        
        for(auto it:nums) player2+=it;
        
        
        player1=win(nums,0,n-1,0);
        
        player2-=player1;
        
        return  (player1>=player2);

        
    }
};
