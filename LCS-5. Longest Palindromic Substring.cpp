class Solution {
public:
    bool isPalin(string s){
        
        
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    string longestPalindrome(string s) {
        
        
        string t=s,ans;
        if(s.size()==1) return s;
        reverse(t.begin(),t.end());
        cout<<s<<" "<<t<<"\n";
        int n=s.size();
        int dp[n+1][n+1];
        int maxlen=0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
               if(i==0 || j==0){
                   dp[i][j]=0;
                   continue;
               }
               if(s[i-1]==t[j-1]){
                   dp[i][j]=1+dp[i-1][j-1];
               }else {dp[i][j]=0;}
                if(dp[i][j]>maxlen){
                    // cout<<s.substr(i-dp[i][j],dp[i][j])<<"\n";
                    string k=s.substr(i-dp[i][j],dp[i][j]);
                    if(isPalin(k)){
                        maxlen=dp[i][j];
                        ans=k;
                    }
                    

                    }
                }
                
            }
        
        
        return ans;
    }
};
