from typing import Dict

class Solution:
    def memo(self,n: int, dp: Dict[int,int])-> int:
        if n in dp :
            return dp[n]
        if n == 0 :
            return 1 
        if n < 0:
            return 0

        op1 = self.memo(n-1,dp)
        op2 = self.memo(n-2,dp)
        dp[n] = op1 + op2

        return  dp[n]

    def climbStairs(self, n: int) -> int:
        dp = {}
        return self.memo(n,dp)

    
        
