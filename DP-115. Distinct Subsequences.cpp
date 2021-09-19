class Solution {
public:
 
        
        int numDistinct(string s, string t) {
        if(t.size() >= s.size())
            return s == t;
        
        long dp[t.size() + 1];

        memset(dp, 0, sizeof(dp));
        dp[0] = 1;

        for(int i = 0; i < s.size(); ++i) {
            long prev = 1;

            for(int j = 0; j < t.size(); ++j) {
                int cur = dp[j+1];
                
                if(s[i] == t[j]) 
                    dp[j+1] += prev;
                
                prev = cur;
            }
        }
        
        return dp[t.size()];
 
    }
};
