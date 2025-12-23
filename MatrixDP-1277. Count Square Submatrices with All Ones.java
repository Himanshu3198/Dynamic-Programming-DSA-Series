class Solution {

    /*
      start with smallest square 2x2  an cell can be square if its top ,left, diagonal left are one 
      and we can make bigger square by adding one on preivous smallest if its there
    */
    public int countSquares(int[][] matrix) {
        
        int n = matrix.length;
        int m = matrix[0].length;
        int[][] dp = new int[n][m];

        int count = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 0) continue;
                if(i==0 || j==0){
                    dp[i][j] = 1;
                }else{
                    dp[i][j] = 1+Math.min(dp[i-1][j],Math.min(dp[i][j-1],dp[i-1][j-1]));
                }

                count += dp[i][j];
            }
        }
        return count;
    }
}
