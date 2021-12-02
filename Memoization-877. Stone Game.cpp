class Solution {
public:
    // memoization
          long long dp[501][501][2];
    
    
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
    
    bool stoneGame(vector<int>& nums) {

    int n=nums.size();
          memset(dp,-1,sizeof(dp));
        
        long long player1=0,player2=0;
        
        for(auto it:nums) player2+=it;
        
        
        player1=win(nums,0,n-1,0);
        
        player2-=player1;
        
        return  (player1>player2);
        
      
      
    }
};


//  binary search
class Solution {
public:
    bool stoneGame(vector<int>& piles) {

        int n=piles.size();
        
        bool flag=true;
        
        int alice=0,bob=0;
       
  
        while(n--){
            
            sort(piles.begin(),piles.end());
            if(flag){
                
                int val=*max_element(piles.begin(),piles.end());
                int idx=lower_bound(piles.begin(),piles.end(),val)-piles.begin();
                
                alice+=piles[idx];
                piles[idx]=0;
                
                flag=false;
            }else{
                   int val=*max_element(piles.begin(),piles.end());
                int idx=lower_bound(piles.begin(),piles.end(),val)-piles.begin();
                
                bob+=piles[idx];
                piles[idx]=0;
                
                flag=true;
                
            }
            
        }
        
      
        
        return alice>bob;
    }
};
