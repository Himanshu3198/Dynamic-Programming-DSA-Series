class Solution
{
public:
    int dp[101][101][201];
    bool solve(string &s1, string &s2, string &s3, int i, int j, int k, string str)
    {
//  condition to check given string is equal to desired string? and all character from both string utilised or not!
        if (str == s3 && i >= s1.size() && j >= s2.size() && k >= s3.size())
        {
            return true;
        }
        if (dp[i][j][k] != -1)
            return dp[i][j][k];
       // if both string has  character available at correct position then try to pick both one by one to 
	   // to get best result
	
        if (k < s3.size() && i < s1.size() && j < s2.size() && s3[k] == s1[i] && s3[k] == s2[j])
        {
            return dp[i][j][k] = solve(s1, s2, s3, i + 1, j, k + 1, str + s1[i]) || solve(s1, s2, s3, i, j + 1, k + 1, str + s2[j]);
        }
		// if only first string has character  available
        else if (k < s3.size() && i < s1.size() && s3[k] == s1[i])
        {

            return dp[i][j][k] = solve(s1, s2, s3, i + 1, j, k + 1, str + s1[i]);
        }
		// if only second string has character  available
        else if (k < s3.size() && j < s2.size() && s3[k] == s2[j])
        {
            return dp[i][j][k] = solve(s1, s2, s3, i, j + 1, k + 1, str + s2[j]);
        }
        return false;
    }
    bool isInterleave(string s1, string s2, string s3)
    {
        int i = 0, j = 0, k = 0;
        memset(dp, -1, sizeof(dp));
        return solve(s1, s2, s3, i, j, k, "");
    }
};
