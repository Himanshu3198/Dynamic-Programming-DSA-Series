class Solution {
public:
    /*  The idea is to sort array and then apply standard LIS to find 
        max length of chain
        time complexity O(nlog(n)+n*n) 
        space complexity O(n)
        */
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        vector<int>dp(n,1);
        sort(pairs.begin(),pairs.end());
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(pairs[i][0]>pairs[j][1])
                  dp[i]=max(dp[i],dp[j]+1);
            }
        }
        return *max_element(dp.begin(),dp.end());
        
    }
};
