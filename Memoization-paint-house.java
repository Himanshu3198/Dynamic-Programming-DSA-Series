class Solution {
    private int solve(int[][] costs,int[][] dp,int idx,int prevColor){

        if(idx == costs.length) return 0;
        if(dp[idx][prevColor] != -1) return dp[idx][prevColor];
        int res =Integer.MAX_VALUE;
        for(int color = 0;color<3;color++){
            if(color == prevColor) continue;
            int curr = solve(costs,dp,idx+1,color);
            int ans = costs[idx][color] + curr;
            res = Math.min(res,ans);
        }

        dp[idx][prevColor] = res;
        return res;
    }
    public int minCost(int[][] costs) {
        
        int n = costs.length;
        int m = 3;
        int [][] dp = new int[n][m];
        for(int i=0;i<n;i++){
            Arrays.fill(dp[i],-1);
        }
        
        int res = Math.min(
                    (costs[0][0] + solve(costs, dp, 1, 0)),
                  Math.min(
                  (costs[0][1] + solve(costs, dp, 1, 1)),
                    (costs[0][2] + solve(costs, dp, 1, 2))
                ));

        return res;

    
    }
}
