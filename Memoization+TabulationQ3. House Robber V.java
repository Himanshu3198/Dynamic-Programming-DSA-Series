class Solution {
    // private long memo(int[] nums, int[] colors, long[][] dp, int idx, int prev) {
    //     if (idx == nums.length) return 0;
    //     if (dp[idx][prev] != -1) return dp[idx][prev];

    //     long pick = 0;
    //     long notPick;

    //    if(prev == 0 || (idx-1 >=0 && colors[idx]!=colors[idx-1])) {
    //         pick = nums[idx] + memo(nums, colors, dp, idx + 1,1);
    //     }

    //     notPick = memo(nums, colors, dp, idx + 1, 0);
    //     return dp[idx][prev] = Math.max(pick, notPick);
    // }
    public long rob(int[] nums, int[] colors) {

        int n = nums.length;
        long [][] dp = new long[n+1][2];

        for(int i=0;i<n;i++){
            Arrays.fill(dp[i],-1);
        }
        dp[0][0] = nums[0];
        dp[0][1] = 0;
        // return memo(nums,colors,dp,0,0);

        for(int idx=1;idx<n;idx++){
            long pick=0;
            long notPick =0;
            for(int prev=0;prev<=1;prev++){

                if(prev == 0 || idx-1>=0 && colors[idx]!=colors[idx-1]){
                     pick = nums[idx]+dp[idx-1][1];
                }
                notPick = dp[idx-1][0];
                dp[idx][prev] = Math.max(pick,notPick);
            }
        }
        return Math.max(dp[n-1][0],dp[n-1][1]);
    }
}
