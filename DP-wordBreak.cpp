// 139. Word Break
// time complexity O(n^2)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        vector<bool>dp(n+1,false);
         dp[n]=true;
        
        for(int i=n-1;i>=0;i--){
             string ans="";
            for(int j=i;j<n;j++){
                ans+=s[j];
                
                if(find(wordDict.begin(),wordDict.end(),ans)!=wordDict.end()==true ){
                    if(dp[j+1]==true){
                        dp[i]=true;
                        break;
                    }
                }
            }
        }
        
        for(int i=0;i<=n;i++){
            cout<<dp[i]<<" ";
        }
        cout<<"\n";
        return dp[0];
        
        
    }
};

