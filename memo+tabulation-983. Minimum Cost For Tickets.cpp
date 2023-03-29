class Solution {
public:
    int dp[366][400];
    int solve(vector<int>&days,vector<int>&costs,int idx,int spent){
        
        
        if(idx==days.size()) return 0;
        if(dp[idx][spent]!=-1) return dp[idx][spent];
        int ans=0;
        if(days[idx]>spent){
              int first=costs[0]+solve(days,costs,idx+1,days[idx]);
              int second=costs[1]+solve(days,costs,idx+1,days[idx]+6);
              int third=costs[2]+solve(days,costs,idx+1,days[idx]+29);
              ans+=min({first,second,third});
          }else
              ans+=solve(days,costs,idx+1,spent);
          
          return dp[idx][spent]=ans;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        return solve(days,costs,0,0);
    }
};
