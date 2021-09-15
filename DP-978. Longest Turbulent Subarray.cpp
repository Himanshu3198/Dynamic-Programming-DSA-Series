// 978. Longest Turbulent Subarray

class Solution {
public:
    // There are 2 possibilities either we check v[0]>v[1] or we check v[0]<v[1]
	// so, we will check for both case
    // Whoever returns maximum that will be our answer
    int maxTurbulenceSize(vector<int>& v) {
        int n=v.size();
        vector<int> dp(n+1,1);
        bool less=true; //first check for dp[0]<dp[1]
        for(int i=1;i<n;i++)
        {
            if(less)
            {
                if(v[i-1]<v[i])
                {
                    dp[i]=dp[i-1]+1;
                }
               
                less=false;
            }
            else{
                if(v[i-1]>v[i])
                {
                    dp[i]=dp[i-1]+1;
                }
              
                less=true;
            }
        }
        
        for(auto it:dp){
            cout<<it<<" ";
        }
        cout<<"\n";
        // find out the best answer from this
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,dp[i]);
            dp[i]=1;
        }
        bool greater=true; //now check for dp[0]>dp[1]
        for(int i=1;i<n;i++)
        {
            if(greater)
            {
                if(v[i-1]>v[i])
                {
                    dp[i]=dp[i-1]+1;
                }
               
                greater=false;
            }
            else{
                if(v[i-1]<v[i])
                {
                    dp[i]=dp[i-1]+1;
                }
               
                greater=true;
            }
        }
         for(auto it:dp){
            cout<<it<<" ";
        }
        cout<<"\n";
        for(int i=0;i<n;i++)
        {
            ans=max(ans,dp[i]);
        }
        return ans;
        
        
    }
};
