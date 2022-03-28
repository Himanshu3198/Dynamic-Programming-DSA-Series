class Solution {
public:
    
       int solve(vector<vector<int>>&piles,int k,int sum,int i,int j){
           
           if(i<0 or i>=piles.size() or j<0 or j>=piles[i].size() or k<=0){
               return 0;
           }
           
           
           
           int option1 =solve(piles,k,sum,i+1,j);
           int option2=piles[i][j]+max(solve(piles,k-1,sum,i,j+1),solve(piles,k-1,sum,i+1,j));
           
           sum+=max({option1,option2});
           return sum;
           
       }
      
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        
        
        int n=piles.size();
        return solve(piles,k,0,0,0);
    }
};
