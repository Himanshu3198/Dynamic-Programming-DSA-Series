174. Dungeon Game

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& d) {
          vector<int> dp(d.size() + 1, INT_MAX);
        dp[d.size() - 1] = 1;
        for (int i = d[0].size() - 1; i >= 0; --i)
            for (int j = d.size() - 1; j >= 0; --j)
                dp[j] = max(1, min(dp[j + 1], dp[j]) - d[j][i]);
        return dp[0];
    }
};
